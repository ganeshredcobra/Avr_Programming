#include <avr/io.h>

void T0Delay();  

void T0Delay()    
{
  TCNT0 = 0xBA;
  TCCR0 = 0x02;
  while((TIFR & (1<<TOV0)) == 0);
  TCCR0 = 0x0;
  TIFR = 0x1;
}

int main()
{
  DDRB = 0xFF;

  while(1)
    {
      //PORTB = 0x55;
      T0Delay();
      //PORTB = 0xAA;
      //T0Delay();
      PORTB = PORTB ^ 0x10;
    }
}
