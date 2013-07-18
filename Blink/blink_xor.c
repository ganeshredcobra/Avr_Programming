/*
 * =====================================================================================
 *
 *       Filename:  blink_xor.c
 *
 *    Description:  Avr blink example with XOR operation
 *
 *        Version:  1.0
 *        Created:  Thursday 18 July 2013 01:10:16  IST
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
		PORTB ^= 1<<PINB0;
		_delay_ms(100);
	}
}
