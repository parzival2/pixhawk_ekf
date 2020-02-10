#ifndef SPIDEVICE_HPP
#define SPIDEVICE_HPP

#include "ch.h"
#include "ch.hpp"
#include "hal.h"

class SPIDevice
{
public:
    // Driver configuration settings
    // clang-format off
    static constexpr uint16_t SPI_BaudRatePrescaler_2    = static_cast<uint16_t>(0x0000); //  42 MHz      21 MHZ
    static constexpr uint16_t SPI_BaudRatePrescaler_4    = static_cast<uint16_t>(0x0008); //  21 MHz      10.5 MHz
    static constexpr uint16_t SPI_BaudRatePrescaler_8    = static_cast<uint16_t>(0x0010); //  10.5 MHz    5.25 MHz
    static constexpr uint16_t SPI_BaudRatePrescaler_16   = static_cast<uint16_t>(0x0018); //  5.25 MHz    2.626 MHz
    static constexpr uint16_t SPI_BaudRatePrescaler_32   = static_cast<uint16_t>(0x0020); //  2.626 MHz   1.3125 MHz
    static constexpr uint16_t SPI_BaudRatePrescaler_64   = static_cast<uint16_t>(0x0028); //  1.3125 MHz  656.25 KHz
    static constexpr uint16_t SPI_BaudRatePrescaler_128  = static_cast<uint16_t>(0x0030); //  656.25 KHz  328.125 KHz
    static constexpr uint16_t SPI_BaudRatePrescaler_256  = static_cast<uint16_t>(0x0038); //  328.125 KHz 164.06 KHz
    // clang-format on

    static constexpr uint8_t DEFAULT_READ_FLAG = 0x80;

    // Constructor
    SPIDevice(SPIDriver* spiDriver, SPIConfig* spiConfig);
    // Destructor
    ~SPIDevice();

    // Functions
    void readRegister(uint8_t registerToRead, void* rxBuffer, uint8_t nBytes);
    void writeRegister(uint8_t registerToWrite, uint8_t dataToWrite, uint8_t nBytes);
    void setReadFlag(const uint8_t readFlag);
    void changeSpiConfig(SPIConfig* spiConfig);
    virtual uint8_t probe() = 0;
protected:
    virtual void initialize() = 0;

private:
    void selectSpiDevice();
    void unSelectSpiDevice();
    /**
     * @brief mSpiDriver The SPIDriver that will be used for SPI communication
     */
    SPIDriver* mSpiDriver;

    /**
     * @brief mSpiConfig The SPIConfig that will be used for SPI communication
     */
    SPIConfig* mSpiConfig;

    /**
     * @brief mReadFlag The read flag that will used while SPI communication
     */
    uint8_t mReadFlag;
};

#endif // SPIDEVICE_HPP
