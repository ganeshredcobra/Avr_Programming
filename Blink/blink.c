/*
 * blink.c
 */

#include <avr/io.h>
#include <util/delay.h>
#define LED PD4

int main(void) {
  // define pd4 as output
  DDRD |= (1 << LED);
  while (1) {
    PORTD |= (1 << LED);    // switch on
    _delay_ms(1000);
    PORTD &= ~(1 << LED);    // switch off
    _delay_ms(1000);
  }
return 0;
}
