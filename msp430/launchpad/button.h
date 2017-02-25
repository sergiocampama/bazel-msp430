#include <msp430.h>
#include <stdint.h>

#include "msp430/launchpad/core.h"

#ifndef __MSP430_LAUNCHPAD_BUTTON
#define __MSP430_LAUNCHPAD_BUTTON

// Button specific ports for configuration.
#define BUTTON_REN P1REN
#define BUTTON_IE P1IE
#define BUTTON_IES P1IES
#define BUTTON_IFG P1IFG

// Button is connected to P1.3
#define BUTTON BIT3

/**
 * Configures the button port to accept interrupts.
 */
ALWAYS_INLINE void button_init() {
  // Enables the pull up resistance for the button.
  BUTTON_REN |= BUTTON;
  // Detect button on high to low edge.
  BUTTON_IES |= BUTTON;
  // Clear the button interrupt.
  BUTTON_IFG &= ~BUTTON;
  // Activate the button interrupt.
  BUTTON_IE |= BUTTON;
}

/**
 * Returns whether the button has an unprocessed interrupt.
 */
ALWAYS_INLINE uint8_t button_interrupted() {
  return BUTTON & BUTTON_IFG;
}

/**
 * Clears the button interrupt flag.
 */
ALWAYS_INLINE void button_clear_interrupt() {
  BUTTON_IFG &= ~BUTTON;
}

#endif  // __MSP430_LAUNCHPAD_BUTTON
