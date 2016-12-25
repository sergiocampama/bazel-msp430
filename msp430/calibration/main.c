#include <msp430.h>

#include "msp430/launchpad/core.h"
#include "msp430/launchpad/watchdog.h"

ALWAYS_INLINE void configure_clock() {
  DCOCTL = 0;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
}

ALWAYS_INLINE void configure_timer() {
  TA1CTL |= TASSEL_2;
  TA1CCR0 = 0x3E8;
  TA1CCR1 = 0x1F4;
  TA1CTL |= MC_1;
  TA1CCTL1 |= OUTMOD_3;

  P2SEL |= BIT1;
  P2DIR |= BIT1;

}

void main() {
  watchdog_config(WDTHOLD);

  configure_clock();
  configure_timer();

  _BIS_SR(CPUOFF + GIE);
}
