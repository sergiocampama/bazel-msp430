#include <msp430.h>

#include "msp430/launchpad/core.h"
#include "msp430/launchpad/led.h"
#include "msp430/launchpad/watchdog.h"

ALWAYS_INLINE void configure_clock() {
  // ACLK sourced from internal VLO, divided by 4 = ~3 kHz.
  BCSCTL1 |= DIVA_2;
  BCSCTL3 |= LFXT1S_2;
}

ALWAYS_INLINE void configure_timer() {
  // Select ACLK, enable interrupt
  TA0CTL |= TASSEL_1 + TAIE;
  TA0CCR0 = 0x5DC;
  // Start counting up to TA0CCR0.
  TA0CTL |= MC_1;
}

void main() {
  watchdog_config(WDTHOLD);

  configure_clock();
  configure_timer();

  led_init();
  led_on(LED_GREEN);

  // Enable global interrupts and enter low power mode.
  _BIS_SR(GIE + LPM3_bits);
}

interrupt(TIMER0_A1_VECTOR) timera0_interrupt_handler() {
	led_toggle(LED_RED + LED_GREEN);
  TA0CTL &= ~TAIFG;
}
