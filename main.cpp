/*
 * This example tries to drive the on-board LEDs using the PWM output.
 */
#include "ch.hpp"
#include "hal.h"
#include "usbcfg.h"
#include "chprintf.h"
#include "mpu6000.hpp"

BaseSequentialStream *chp = (BaseSequentialStream *)(&SDU1);

/* Thread definition */
static THD_WORKING_AREA(ld4ledblink, 128);
static THD_FUNCTION(ld4LedThread, arg){
    (void)arg;
    /* Set thread name */
    chRegSetThreadName("ld4LedThread");
    /* Thread should not return, so begin a while loop */
    while(TRUE)
    {
        palToggleLine(HAL_GPIO_AMBER_LED);
        chThdSleepMilliseconds(1000);
    }
}

/*
 * Thread definition for MPU6000 thread
 */
static THD_WORKING_AREA(mpu6000area, 512);
static THD_FUNCTION(mpu6000thread, arg)
{
    (void)arg;
    // Set thread name
    chRegSetThreadName("mpu6000thread");
    // Instance of the class MPU6000
    MPU6000 mpu6000;
    AccelData accData;
    GyroData gyroData;
    // Thread should not return
    while(TRUE)
    {
        // Probe the MPU6000 and print the result
        chprintf(chp, "Return result of probe : %x\n", mpu6000.probe());
        mpu6000.getAccelData(accData);
        mpu6000.getGyroData(gyroData);
        chprintf(chp, "[ACCEL] X:%f, Y:%f, Z:%f\n", accData.getAccelX(), accData.getAccelY(), accData.getAccelZ());
        chprintf(chp, "[GYRO]  X:%f, Y:%f, Z:%f\n", gyroData.getAngularVelX(), gyroData.getAngularVelY(), gyroData.getAngularVelZ());
        chThdSleepMilliseconds(100);
    }
}


/*
 * Application entry point.
 */
int main(void) {
    /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
    halInit();
    chibios_rt::System::init();

    // Initialize Serial-USB driver
    sduObjectInit(&SDU1);
    sduStart(&SDU1, &serusbcfg);

    /*
       * Activates the USB driver and then the USB bus pull-up on D+.
       * Note, a delay is inserted in order to not have to disconnect the cable
       * after a reset.
       */
    usbDisconnectBus(serusbcfg.usbp);
    chThdSleepMilliseconds(1500);
    usbStart(serusbcfg.usbp, &usbcfg);
    usbConnectBus(serusbcfg.usbp);

    // Create a thread for LED and SPI
    chThdCreateStatic(ld4ledblink, sizeof(ld4ledblink), NORMALPRIO + 1,
                      ld4LedThread, NULL);
    chThdCreateStatic(mpu6000area, sizeof(mpu6000area), NORMALPRIO + 1,
                      mpu6000thread, NULL);

    /*
   * Normal main() thread activity, in this demo it does nothing.
   */
    while (true) {
        chThdSleepMicroseconds(1000);
    }
    return 0;
}
