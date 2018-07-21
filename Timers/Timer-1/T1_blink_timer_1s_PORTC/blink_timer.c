#include <avr/io.h>

void T1Delay();  

void T1Delay()    
{
  TCNT1H = 0x85;
  TCNT1L = 0xEE;

  TCCR1A = 0x00;
  TCCR1B = 0x04;
  
  while((TIFR & (1<<TOV1)) == 0);
  
  TCCR1B = 0x0;
  TIFR = 0x1 << TOV1;
}

int main()
{
  DDRC = 0xFF;

  while(1)
    {
      PORTC = PORTC ^ (1<<PC4);
      T1Delay();
    }
}
