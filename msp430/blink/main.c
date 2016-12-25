#include <msp430.h>

#include "msp430/launchpad/button.h"
#include "msp430/launchpad/core.h"
#include "msp430/launchpad/led.h"
#include "msp430/launchpad/watchdog.h"

void main() {
  watchdog_config(WDTHOLD);

  led_init();
  button_init();

  led_on(LED_GREEN);

  // Enable global interrupts and enter low power mode.
  _BIS_SR(GIE + LPM4_bits);
}

interrupt(PORT1_VECTOR) port1_interrupt_handler() {
	// If the button was pressed, toggle the LEDs.
	if (button_interrupted()) {
    led_toggle(LED_RED + LED_GREEN);
    button_clear_interrupt();
	}
}
