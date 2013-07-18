/*
 * =====================================================================================
 *
 *       Filename:  blink_binary.c
 *
 *    Description:  Avr blink using binay
 *
 *        Version:  1.0
 *        Created:  Thursday 18 July 2013 12:54:06  IST
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
	DDRB=0b0000001;
	while(1)
	{
		PORTB=0b0000001;
	}
}
