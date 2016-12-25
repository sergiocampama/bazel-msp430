#include <msp430.h>
#include <stdint.h>

#include "msp430/launchpad/core.h"

#ifndef __MSP430_LAUNCHPAD_LED
#define __MSP430_LAUNCHPAD_LED

// LED specific ports for configuration.
#define LED_DIR P1DIR
#define LED_OUT P1OUT

// The green led is connected to P1.6 and the red one to P1.0.
#define LED_RED BIT0
#define LED_GREEN BIT6

/**
 * Configures the button port to accept interrupts.
 */
ALWAYS_INLINE void led_init() {
  // Set direction as output.
  LED_DIR |= LED_RED + LED_GREEN;
  // Set status to off.
  LED_OUT &= ~(LED_GREEN + LED_RED);
}

/**
 * Turns on the LEDs specified in led_id.
 */
ALWAYS_INLINE void led_on(uint8_t led_id) {
  LED_OUT |= led_id;
}

/**
 * Turns off the LEDs specified in led_id.
 */
ALWAYS_INLINE void led_off(uint8_t led_id) {
  LED_OUT &= ~led_id;
}

/**
 * Toggles the LEDs specified in led_id.
 */
ALWAYS_INLINE void led_toggle(uint8_t led_id) {
  LED_OUT ^= led_id;
}

#endif  // __MSP430_LAUNCHPAD_LED
