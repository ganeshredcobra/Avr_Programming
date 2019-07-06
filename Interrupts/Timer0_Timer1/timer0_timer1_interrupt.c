#include <avr/io.h>
#include <avr/interrupt.h>

int main()
{

  DDRA = 0xFF;
  DDRD = 0xFF;
  DDRB |= 0x40;
  PORTB |= 0x01;

  TCNT0 = -200;
  TCCR0 = 0x06;

  TCNT1H = (-31250)>>8;
  TCNT1L = (-31250)& 0xFF;
  TCCR1A = 0x00;
  TCCR1B = 0x04;

  TIMSK = (1<<TOIE0)|(1<<TOIE1);
  sei();

  DDRC = 0x00;
  DDRD = 0xFF;

  while(1)
    PORTD = PINC;

}

ISR(TIMER0_OVF_vect)
{
  TCNT0 = -200;
  PORTB ^= 0x40;
}

ISR(TIMER1_OVF_vect)
{
  TCNT1H = (-31250)>>8;
  TCNT1L = (-31250)& 0xFF;
  PORTA++;
}

