#include <msp430.h>
#include <stdint.h>

#include "msp430/launchpad/core.h"

#ifndef __MSP430_LAUNCHPAD_WATCHDOG
#define __MSP430_LAUNCHPAD_WATCHDOG

/**
 * Turns off the WatchDog. This disables automatic resets when the dog hasn't
 * been pet.
 */
ALWAYS_INLINE void watchdog_config(uint8_t config) {
  WDTCTL = WDTPW + config;
}

/**
 * Resets the microcontroller by writing to WDTCTL without the password.
 */
ALWAYS_INLINE void watchdog_reset() {
  WDTCTL = 0x00;
}

#endif  // __MSP430_LAUNCHPAD_WATCHDOG
