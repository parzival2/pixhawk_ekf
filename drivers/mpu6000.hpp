#ifndef MPU6000_HPP
#define MPU6000_HPP
#include "ch.hpp"
#include "datapackets/acceldata.hpp"
#include "datapackets/gyrodata.hpp"
#include "spidevice.hpp"

class MPU6000 : public SPIDevice {
public:
  // Default SPI Config
  SPIConfig spiConfig = {false,
                         NULL,
                         GPIOC,
                         HAL_GPIO_PIN_MPU_CS,
                         SPIDevice::SPI_BaudRatePrescaler_32,
                         0};
  // Constructor
  MPU6000();
  ~MPU6000();
  // Get Accel data
  void getAccelData(AccelData &accelData);
  void getGyroData(GyroData &gyroData);
  bool isInitialized();
  uint8_t probe() override;

protected:
  void initialize() override;

private:
  float mAccelDivider;
  float mGyroDivider;
};

#endif // MPU6000_HPP
