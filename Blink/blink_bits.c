/*
 * =====================================================================================
 *
 *       Filename:  blink_bits.c
 *
 *    Description:  Avr blink program bitwise operation
 *
 *        Version:  1.0
 *        Created:  Thursday 18 July 2013 01:03:50  IST
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
	while(1)
	{
		PORTB |= 1<<PINB0;
		_delay_ms(100);
		PORTB &= ~(1<<PINB0);
		_delay_ms(100);
	}
}
