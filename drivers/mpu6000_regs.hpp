#ifndef MPU6000_REGS_HPP
#define MPU6000_REGS_HPP

class MPU6000Registers
{
public:
    //clang-format off
    static constexpr uint8_t MPU6000_AUX_VDDIO          =   0x01;   // R/W
    static constexpr uint8_t MPU6000_SMPLRT_DIV         =   0x19;   // R/W
    static constexpr uint8_t MPU6000_CONFIG             =   0x1A;   // R/W
    static constexpr uint8_t MPU6000_GYRO_CONFIG        =   0x1B;   // R/W
    static constexpr uint8_t MPU6000_ACCEL_CONFIG       =   0x1C;   // R/W
    static constexpr uint8_t MPU6000_FF_THR             =   0x1D;   // R/W
    static constexpr uint8_t MPU6000_FF_DUR             =   0x1E;   // R/W
    static constexpr uint8_t MPU6000_MOT_THR            =   0x1F;   // R/W
    static constexpr uint8_t MPU6000_MOT_DUR            =   0x20;   // R/W
    static constexpr uint8_t MPU6000_ZRMOT_THR          =   0x21;   // R/W
    static constexpr uint8_t MPU6000_ZRMOT_DUR          =   0x22;   // R/W
    static constexpr uint8_t MPU6000_FIFO_EN            =   0x23;   // R/W
    static constexpr uint8_t MPU6000_I2C_MST_CTRL       =   0x24;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV0_ADDR      =   0x25;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV0_REG       =   0x26;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV0_CTRL      =   0x27;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV1_ADDR      =   0x28;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV1_REG       =   0x29;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV1_CTRL      =   0x2A;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV2_ADDR      =   0x2B;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV2_REG       =   0x2C;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV2_CTRL      =   0x2D;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV3_ADDR      =   0x2E;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV3_REG       =   0x2F;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV3_CTRL      =   0x30;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV4_ADDR      =   0x31;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV4_REG       =   0x32;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV4_DO        =   0x33;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV4_CTRL      =   0x34;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV4_DI        =   0x35;   // R
    static constexpr uint8_t MPU6000_I2C_MST_STATUS     =   0x36;   // R
    static constexpr uint8_t MPU6000_INT_PIN_CFG        =   0x37;   // R/W
    static constexpr uint8_t MPU6000_INT_ENABLE         =   0x38;   // R/W
    static constexpr uint8_t MPU6000_INT_STATUS         =   0x3A;   // R
    static constexpr uint8_t MPU6000_ACCEL_XOUT_H       =   0x3B;   // R
    static constexpr uint8_t MPU6000_ACCEL_XOUT_L       =   0x3C;   // R
    static constexpr uint8_t MPU6000_ACCEL_YOUT_H       =   0x3D;   // R
    static constexpr uint8_t MPU6000_ACCEL_YOUT_L       =   0x3E;   // R
    static constexpr uint8_t MPU6000_ACCEL_ZOUT_H       =   0x3F;   // R
    static constexpr uint8_t MPU6000_ACCEL_ZOUT_L       =   0x40;   // R
    static constexpr uint8_t MPU6000_TEMP_OUT_H         =   0x41;   // R
    static constexpr uint8_t MPU6000_TEMP_OUT_L         =   0x42;   // R
    static constexpr uint8_t MPU6000_GYRO_XOUT_H        =   0x43;   // R
    static constexpr uint8_t MPU6000_GYRO_XOUT_L        =   0x44;   // R
    static constexpr uint8_t MPU6000_GYRO_YOUT_H        =   0x45;   // R
    static constexpr uint8_t MPU6000_GYRO_YOUT_L        =   0x46;   // R
    static constexpr uint8_t MPU6000_GYRO_ZOUT_H        =   0x47;   // R
    static constexpr uint8_t MPU6000_GYRO_ZOUT_L        =   0x48;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_00   =   0x49;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_01   =   0x4A;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_02   =   0x4B;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_03   =   0x4C;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_04   =   0x4D;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_05   =   0x4E;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_06   =   0x4F;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_07   =   0x50;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_08   =   0x51;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_09   =   0x52;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_10   =   0x53;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_11   =   0x54;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_12   =   0x55;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_13   =   0x56;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_14   =   0x57;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_15   =   0x58;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_16   =   0x59;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_17   =   0x5A;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_18   =   0x5B;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_19   =   0x5C;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_20   =   0x5D;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_21   =   0x5E;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_22   =   0x5F;   // R
    static constexpr uint8_t MPU6000_EXT_SENS_DATA_23   =   0x60;   // R
    static constexpr uint8_t MPU6000_MOT_DETECT_STATUS  =   0x61;   // R
    static constexpr uint8_t MPU6000_I2C_SLV0_DO        =   0x63;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV1_DO        =   0x64;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV2_DO        =   0x65;   // R/W
    static constexpr uint8_t MPU6000_I2C_SLV3_DO        =   0x66;   // R/W
    static constexpr uint8_t MPU6000_I2C_MST_DELAY_CTRL =   0x67;   // R/W
    static constexpr uint8_t MPU6000_SIGNAL_PATH_RESET  =   0x68;   // R/W
    static constexpr uint8_t MPU6000_MOT_DETECT_CTRL    =   0x69;   // R/W
    static constexpr uint8_t MPU6000_USER_CTRL          =   0x6A;   // R/W
    static constexpr uint8_t MPU6000_PWR_MGMT_1         =   0x6B;   // R/W
    static constexpr uint8_t MPU6000_PWR_MGMT_2         =   0x6C;   // R/W
    static constexpr uint8_t MPU6000_FIFO_COUNTH        =   0x72;   // R/W
    static constexpr uint8_t MPU6000_FIFO_COUNTL        =   0x73;   // R/W
    static constexpr uint8_t MPU6000_FIFO_R_W           =   0x74;   // R/W
    static constexpr uint8_t MPU6000_WHO_AM_I           =   0x75;   // R

    /**
     * CONFIG - PWR_MGMT_1
     */
    static constexpr uint8_t PWR_MGMT_1_RESET_DEVICE    =   0x80;
    static constexpr uint8_t PWR_MGMT_1_SLEEP           =   0x40;
    static constexpr uint8_t PWR_MGMT_1_CYCLE           =   0x20;
    static constexpr uint8_t PWR_MGMT_1_TEMP_DIS        =   0x08;
    // Clock select
    static constexpr uint8_t PWR_MGMT_1_CLKSEL_INTERNAL  =  0x00;
    static constexpr uint8_t PWR_MGMT_1_CLKSEL_GYROX     =  0x01;
    static constexpr uint8_t PWR_MGMT_1_CLKSEL_GYROY     =  0x02;
    static constexpr uint8_t PWR_MGMT_1_CLKSEL_GYROZ     =  0x03;
    static constexpr uint8_t PWR_MGMT_1_CLKSEL_PLL_32KHZ =  0x04;
    static constexpr uint8_t PWR_MGMT_1_CLKSEL_PLL_19MHZ =  0x05;

    /**
     * SIGNAL_PATH_RESET
     */
    static constexpr uint8_t SIGNAL_PATH_RESET_GYRO      =  0x04;
    static constexpr uint8_t SIGNAL_PATH_RESET_ACCEL     =  0x02;
    static constexpr uint8_t SIGNAL_PATH_RESET_TEMP      =  0x00;
    static constexpr uint8_t SIGNAL_PATH_RESET_ALL       =  0x07;

    /**
     * USER_CONTROL
     */
    static constexpr uint8_t BIT_IF_I2C_DISABLED         =  0x10;

    /**
     * GYRO_CONFIG
     */
    static constexpr uint8_t GYRO_CONFIG_FS_SEL_250D     =  0x00;
    static constexpr uint8_t GYRO_CONFIG_FS_SEL_500D     =  0x08;
    static constexpr uint8_t GYRO_CONFIG_FS_SEL_1000D    =  0x10;
    static constexpr uint8_t GYRO_CONFIG_FS_SEL_2000D    =  0x18;

    /**
     * ACCEL_CONFIG
     */
    static constexpr uint8_t ACCEL_CONFIG_FS_SEL_2G      =  0x00;
    static constexpr uint8_t ACCEL_CONFIG_FS_SEL_4G      =  0x08;
    static constexpr uint8_t ACCEL_CONFIG_FS_SEL_8G      =  0x10;
    static constexpr uint8_t ACCEL_CONFIG_FS_SEL_16G     =  0x18;

    static constexpr uint8_t READ_FLAG                   =  0x80;
    //clang-format off
};

#endif // MPU6000_REGS_HPP
