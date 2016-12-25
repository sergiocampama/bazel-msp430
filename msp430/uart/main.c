#include <msp430.h>

#include "msp430/launchpad/core.h"
#include "msp430/launchpad/led.h"
#include "msp430/launchpad/watchdog.h"

#define TX_LED LED_RED
#define RX_LED LED_GREEN

#define TXD BIT2
#define RXD BIT1

const char string[] = { "Hello world!\r\n" };
unsigned int i;

ALWAYS_INLINE void configure_clock() {
  DCOCTL = 0;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
}

ALWAYS_INLINE void configure_uart() {
  UCA0CTL1 |= UCSWRST;

  UCA0CTL1 |= UCSSEL_2;
  // 9600 8N1 @ 1MHZ
  UCA0BR0 = 0x68;
  UCA0BR1 = 0x00;
  UCA0MCTL = UCBRS_1;

  P1SEL |= RXD + TXD;
  P1SEL2 |= RXD + TXD;

  UCA0CTL1 &= ~UCSWRST;
  UC0IE |= UCA0RXIE;
}

void main() {
  watchdog_config(WDTHOLD);

  led_init();

  configure_clock();
  configure_uart();

  _BIS_SR(CPUOFF + GIE);
}

// Port 1 interrupt.
interrupt(USCIAB0RX_VECTOR) rx_interrupt_handler() {
  led_on(RX_LED + TX_LED);
  UCA0TXBUF = UCA0RXBUF;
  led_off(RX_LED + TX_LED);
}
