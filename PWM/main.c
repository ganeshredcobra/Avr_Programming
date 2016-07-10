#include <avr/io.h>
#include <avr/interrupt.h>

void pwm_tc0(uint8_t csb, uint8_t ocrval)
{
// Set TCCR0 in the Fast PWM mode
    TCCR0 =(1 << WGM01) | (1 << WGM00) | (1 << COM01) | csb;
    OCR0 = ocrval;
    TCNT0 = 0;
    DDRB |= (1 << PB3);
}

uint8_t  csb = 1;            // Clock select bits
uint8_t  ocrval = 63;   // Output Compare register  OCR0 , decides duty cycle

int main()
{
    pwm_tc0(csb, ocrval);    // 25% duty cycle PWM output on pin PB3 (OC0)
}
