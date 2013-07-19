/*
 * =====================================================================================
 *
 *       Filename:  button_delay.c
 *
 *    Description:  Change delay with respect to button press
 *
 *        Version:  1.0
 *        Created:  Friday 19 July 2013 01:03:40  IST
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
		if(bit_is_clear(PINB,1))
		{
			_delay_ms(100);
		}
		else
		{
			_delay_ms(500);
		}
	}
}
