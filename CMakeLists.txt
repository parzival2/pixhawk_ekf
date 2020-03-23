cmake_minimum_required(VERSION 3.0.0)
project(pixhawk_ekf VERSION 0.1.0)

# Set the board file
set(CHIBIOS_BOARD_CMAKE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/board/board.cmake)

if(CMAKE_BUILD_TYPE MATCHES Release)
    add_definitions("-DOSAL_DBG_ENABLE_ASSERTS=false -DOSAL_DBG_ENABLE_CHECKS=false")
else()
    add_definitions("-DOSAL_DBG_ENABLE_ASSERTS=true -DOSAL_DBG_ENABLE_CHECKS=true")
endif()

# Set Headers needed
set(HEADERS
    chconf.h
    halconf.h
    mcuconf.h
    usbcfg.h
    ChibiOSHardware.h
    ros.h
    # Drivers
    drivers/spidevice.hpp
    drivers/mpu6000.hpp
    # Data packets
    datapackets/acceldata.hpp
    datapackets/gyrodata.hpp)

set(SOURCES
    usbcfg.c
    # Drivers
    drivers/spidevice.cpp
    drivers/mpu6000.cpp
    # Data packets
    datapackets/acceldata.cpp
    datapackets/gyrodata.cpp
    # ROS
    ros_lib/duration.cpp
    ros_lib/time.cpp
    main.cpp)

# Include chibios
include(${CMAKE_CURRENT_SOURCE_DIR}/ChibiOS_18.2.x/chibios.cmake)
# For printing float values
add_definitions("-DCHPRINTF_USE_FLOAT")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ros_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
add_chibios_executable(pixhawk_ekf
                       ${HEADERS}
                       ${SOURCES})
