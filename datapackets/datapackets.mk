DATAPACKETCPP = $(PIXHAWK_EKF)/datapackets/gyrodata.cpp \
                $(PIXHAWK_EKF)/datapackets/acceldata.cpp

DATAPACKETINC = $(PIXHAWK_EKF)/datapackets

ALLCPPSRC += $(DATAPACKETCPP)
ALLINC += $(DATAPACKETINC)
