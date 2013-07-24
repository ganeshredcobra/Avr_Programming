/*
 * =====================================================================================
 *
 *       Filename:  button_switch_set.c
 *
 *    Description:  blink led when button is set
 *
 *        Version:  1.0
 *        Created:  Thursday 25 July 2013 01:37:50  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ganesh H (), ganeshredcobra@gmail.com
 *        Company:  space-kerala.org
 *
 * =====================================================================================
 */

#include <avr/io.h>
#include <avr/delay.h>

int main()
{
	DDRB |= 1<<PINB0;
	DDRB &= ~(1<<PINB1);
	PORTB |= 1<<PINB1;
	while(1)
	{
		PORTB ^= 1<<PINB0;
		if(bit_is_set(PINB,1))
		{
			_delay_ms(100);
		}
		else
		{
			_delay_ms(500);
		}
	}
}
