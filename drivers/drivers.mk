DRIVERSCPPSRC = $(PIXHAWK_EKF)/drivers/spidevice.cpp \
                $(PIXHAWK_EKF)/drivers/mpu6000.cpp

DRIVERSINC = $(PIXHAWK_EKF)/drivers

ALLCPPSRC += $(DRIVERSCPPSRC)
ALLINC += $(DRIVERSINC)
