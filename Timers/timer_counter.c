/*
 * =====================================================================================
 *
 *       Filename:  timer_counter.c
 *
 *    Description:  Testing 16 bit timers
 *
 *        Version:  1.0
 *        Created:  Sunday 29 December 2013 01:03:30  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ganesh H (), ganeshredcobra@gmail.com
 *        Company:  space-kerala.org
 *
 * =====================================================================================
 */

#include <avr/io.h>

int main()
{
	DDRB |= 1<<PINB0;
	PORTB = 0b00000000;
	TCCR1B |= 1<<CS10;
	
	while(1)
	{
		if(TCNT1 > 10000)
		{
			TCNT1 = 0;
			PORTB ^= 1<<PINB0;
		}

	}
}
