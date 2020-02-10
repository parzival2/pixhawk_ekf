#include "spidevice.hpp"

/**
 * @brief SPIDevice::SPIDevice Constructor
 * @param spiDriver The SPIdriver that will used for SPI communication
 * @param spiConfig The SPI config that will be used for SPI communication
 */
SPIDevice::SPIDevice(SPIDriver* spiDriver, SPIConfig* spiConfig)
    : mSpiDriver(spiDriver)
    , mSpiConfig(spiConfig)
    , mReadFlag(DEFAULT_READ_FLAG)
{

}

/**
 * @brief SPIDevice::~SPIDevice Destructor
 */
SPIDevice::~SPIDevice()
{

}

/**
 * @brief SPIDevice::readRegister Read register or registers depending on the number of bytes that has to be read
 * @param registerToRead The register that has to be read
 * @param rxBuffer The receive buffer that will be filled up
 * @param nBytes Number of bytes to be read
 */
void SPIDevice::readRegister(uint8_t registerToRead, void *rxBuffer, uint8_t nBytes)
{
    uint8_t txBuffer = registerToRead | mReadFlag;
    selectSpiDevice();
    spiSend(mSpiDriver, 1, &txBuffer);
    spiReceive(mSpiDriver, nBytes, rxBuffer);
    unSelectSpiDevice();
}

/**
 * @brief SPIDevice::writeRegister Write register to the device
 * @param registerToWrite The register to be written
 * @param dataToWrite The data that needs to be written to the register
 * @param nBytes Number of bytes that need to be written to the register
 */
void SPIDevice::writeRegister(uint8_t registerToWrite, uint8_t dataToWrite, uint8_t nBytes)
{
    uint8_t txBuffer[2];
    txBuffer[0] = registerToWrite;
    txBuffer[1] = dataToWrite;
    selectSpiDevice();
    spiSend(mSpiDriver, nBytes, &txBuffer);
    unSelectSpiDevice();
}

/**
 * @brief SPIDevice::changeSpiConfig Change the SPI configuration
 * @param spiConfig The SPI config that has to be used for the SPI communication
 */
void SPIDevice::changeSpiConfig(SPIConfig* spiConfig)
{
    mSpiConfig = spiConfig;
}

/**
 * @brief SPIDevice::setReadFlag Sets the read flag that will be used to read the register
 * @param readFlag The read flag that should be utilized.
 */
void SPIDevice::setReadFlag(const uint8_t readFlag)
{
    mReadFlag = readFlag;
}

/**
 * @brief SPIDevice::selectSpiDevice Selects SPI device
 */
void SPIDevice::selectSpiDevice()
{
    // Acquire SPI bus
    spiAcquireBus(mSpiDriver);

    // Start SPI transaction
    spiStart(mSpiDriver, mSpiConfig);

    // Select the SPI device
    spiSelect(mSpiDriver);

}

/**
 * @brief SPIDevice::unSelectSpiDevice Unselects and frees the SPI device
 */
void SPIDevice::unSelectSpiDevice()
{
    // Unselect the slave
    spiUnselect(mSpiDriver);

    // Release bus to be used by others
    spiReleaseBus(mSpiDriver);
}
