#ifndef F_CPU
#define F_CPU 8000000UL
#endif
 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
 
#define ACK 0x7E
#define LONG_TIME 10000
 
//Initialize SPI Master Device
void spi_init_master (void)
{
    DDRB = (1<<5)|(1<<7);              //Set MOSI, SCK as Output
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0); //Enable SPI, Set as Master
                                       //Prescaler: Fosc/16, Enable Interrupts
}
 
//Function to send and receive data
unsigned char spi_tranceiver (unsigned char data)
{
	PORTD|=(1<<0);
    SPDR = data;                       //Load data into the buffer
    while(!(SPSR & (1<<SPIF) ));       //Wait until transmission complete
    return(SPDR);                      //Return received data
    PORTD=(0<<0);
}
 
//Function to blink LED
void led_blink (uint16_t i)
{
    //Blink LED "i" number of times
    for (; i>0; --i)
    {
        PORTD|=(1<<6);
        _delay_ms(100);
        PORTD=(0<<6);
        _delay_ms(100);
    }
}
 
//Main
int main(void)
{
    spi_init_master();                  //Initialize SPI Master
    DDRD |= 0x01;                       //PD0 as Output
 
    unsigned char data;                 //Received data stored here
    uint8_t x = 0;                      //Counter value which is sent
 
    while(1)
    {
        data = 0x00;                    //Reset ACK in "data"
        data = spi_tranceiver(++x);     //Send "x", receive ACK in "data"
        if(data == ACK) {               //Check condition
            //If received data is the same as ACK, blink LED "x" number of times
            led_blink(x);
        }
        else {
            //If received data is not ACK, then blink LED for a long time so as to determine error
            led_blink(LONG_TIME);
        }
        _delay_ms(500);                 //Wait
    }
}
