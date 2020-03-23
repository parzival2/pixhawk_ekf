# The board includes and sources for STM32F4Discovery
# Get the current directory of this file.
get_filename_component(CHIBIOS_BOARD_DIR ${CMAKE_CURRENT_LIST_FILE} DIRECTORY)

# Includes
set(CHIBIOS_BOARD_INCLUDE_DIR ${CHIBIOS_BOARD_DIR})

# Sources
set(CHIBIOS_BOARD_SRC ${CHIBIOS_BOARD_DIR}/board.c)

# Include platform details
include(${CHIBIOS_ROOT_DIR}/hal/ports/STM32/STM32F4xx/platform.cmake)

# Linker script
# Set linker script
set(CHIBIOS_LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/startup/Pixhawk_Linkerscript.ld)
message(STATUS "Linker script : ${CHIBIOS_LINKER_SCRIPT}")