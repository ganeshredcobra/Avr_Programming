#include <avr/io.h>

void T1Delay();  

void T1Delay()    
{
  TCNT1H = 0xC1;
  TCNT1L = 0x80;

  TCCR1A = 0x00;
  TCCR1B = 0x01;
  
  while((TIFR & (1<<TOV1)) == 0);
  
  TCCR1B = 0x0;
  TIFR = 0x1 << TOV1;
}

int main()
{
  DDRB = 0xFF;

  while(1)
    {
      T1Delay();
      PORTB = PORTB ^ 0x10;
    }
}
