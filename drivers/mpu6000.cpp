#include "mpu6000.hpp"
#include "mpu6000_regs.hpp"

/**
 * @brief mpu6000::mpu6000 Constructor
 */
MPU6000::MPU6000()
    : SPIDevice(&SPID1, &spiConfig)
    , mAccelDivider(8192.0)
    , mGyroDivider(131.0)
{
    initialize();
}

/**
 * @brief MPU6000::~MPU6000 Destructor
 */
MPU6000::~MPU6000()
{

}

/**
 * @brief MPU6000::probe Probes to check whether the MPU6000 can be found
 * @return The return value of WHO_AM_I register.
 */
uint8_t MPU6000::probe()
{
    uint8_t whoAmIResp;
    // Probe whether the MPU600 can be found
    this->readRegister(MPU6000Registers::MPU6000_WHO_AM_I,
                       &whoAmIResp,
                       1);
    return whoAmIResp;
}

/**
 * @brief MPU6000::initialize Initializes the MPU6000 device. It requires some strict
 * initialization procedures.
 * 1) First the device has to be reset by writing DEVICE_RESET to PWR_MGMT_1 register
 * 2) The SIGNAL_PATH_RESET should be set to reset
 * 3) Select internal clock to either one of the gyro axes
 * 4) Disable I2C bus if not needed
 */
void MPU6000::initialize()
{
    // Reset the internal registers
    this->writeRegister(MPU6000Registers::MPU6000_PWR_MGMT_1,
                        MPU6000Registers::PWR_MGMT_1_RESET_DEVICE,
                        2);
    chThdSleepMilliseconds(100);
    // Signal path reset
    this->writeRegister(MPU6000Registers::MPU6000_SIGNAL_PATH_RESET,
                        MPU6000Registers::SIGNAL_PATH_RESET_ALL,
                        2);
    chThdSleepMilliseconds(100);
    // Set internal clock to GYROZ
    this->writeRegister(MPU6000Registers::MPU6000_PWR_MGMT_1,
                        MPU6000Registers::PWR_MGMT_1_CLKSEL_GYROZ,
                        2);
    chThdSleepMilliseconds(100);
    // Disable I2C
    this->writeRegister(MPU6000Registers::MPU6000_USER_CTRL,
                        MPU6000Registers::BIT_IF_I2C_DISABLED,
                        2);
    chThdSleepMilliseconds(100);
    // Write DLPF config for Accel and Gyro to decide up on the dividers
    this->writeRegister(MPU6000Registers::MPU6000_GYRO_CONFIG,
                        MPU6000Registers::GYRO_CONFIG_FS_SEL_250D,
                        2);
    chThdSleepMilliseconds(100);
    this->writeRegister(MPU6000Registers::MPU6000_ACCEL_CONFIG,
                        MPU6000Registers::ACCEL_CONFIG_FS_SEL_4G,
                        2);
    chThdSleepMilliseconds(100);
    // After this step the MPU6000 should have initialized.
    // MPU6000 can be checked whether it has initialized by reading the PWR_MGMT_1 register.
}

/**
 * @brief MPU6000::isInitialized Check whether the MPU6000 is initialized and can be used to acquire data
 * @return The result whether the device is Initialized or not
 */
bool MPU6000::isInitialized()
{
    uint8_t pwrManagementReg = 0;
    // Can be checked by reading the PWR_MGMT_1 register
    this->readRegister(MPU6000Registers::MPU6000_PWR_MGMT_1, &pwrManagementReg, 1);
    if(pwrManagementReg == MPU6000Registers::PWR_MGMT_1_CLKSEL_GYROZ)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief MPU6000::getAccelData Returns the fresh accelerometer data from the device
 * @param[in/out] accelData The acceleration data
 */
void MPU6000::getAccelData(AccelData &accelData)
{
    uint8_t accelRecBuffer[6];
    this->readRegister(MPU6000Registers::MPU6000_ACCEL_XOUT_H,
                 &accelRecBuffer,
                 6);
    // Combine the high byte and low byte
    int16_t tempAccelX = ((int16_t)accelRecBuffer[0] << 8) | accelRecBuffer[1];
    int16_t tempAccelY = ((int16_t)accelRecBuffer[2] << 8) | accelRecBuffer[3];
    int16_t tempAccelZ = ((int16_t)accelRecBuffer[4] << 8) | accelRecBuffer[5];
    // Set the accel data
    accelData.setAccelX((float)(tempAccelX / mAccelDivider));
    accelData.setAccelY((float)(tempAccelY / mAccelDivider));
    accelData.setAccelZ((float)(tempAccelZ / mAccelDivider));
}

void MPU6000::getGyroData(GyroData &gyroData)
{
    uint8_t gyroRecBuffer[6];
    this->readRegister(MPU6000Registers::MPU6000_GYRO_XOUT_H,
                       &gyroRecBuffer,
                       6);
    // Combine high byte and low byte
    int16_t tempGyroX = ((int16_t)gyroRecBuffer[0] << 8) | gyroRecBuffer[1];
    int16_t tempGyroY = ((int16_t)gyroRecBuffer[2] << 8) | gyroRecBuffer[3];
    int16_t tempGyroZ = ((int16_t)gyroRecBuffer[4] << 8) | gyroRecBuffer[5];
    // Set the gyro data
    gyroData.setAngularVelX((float)(tempGyroX / mGyroDivider));
    gyroData.setAngularVelY((float)(tempGyroY / mGyroDivider));
    gyroData.setAngularVelZ((float)(tempGyroZ / mGyroDivider));
}


