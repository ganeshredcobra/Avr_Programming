#Timer 0 Explained

##Registers

Register | Description
------------ | -------------
 TCCR0 |Timer Counter Control Register
 TCNT0 | Timer/CounterRegister
 
##Code Explanation

###Init Function
```c
void timer0_init()
{
    // set up timer with prescaler = 1024
    TCCR0 |= (1 << CS02)|(1 << CS00);
  
    // initialize counter
    TCNT0 = 0;
}
```
###TCCR0 - Timer Counter Control Register
![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/Timers/IMG/TCCR0.png "TCCR0")

Bit 2:0 – CS02:0: Clock Select
The three Clock Select bits select the clock source to be used by the Timer/Counter.

###CSB - Clock Select Bits

![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/Timers/IMG/CSB.png "TCCR0")
 
###TCNT0 - Timer/Counter Register

![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/Timers/IMG/TCNTO.png "TCNT0")

The Timer/Counter Register gives direct access, both for read and write operations, to the
Timer/Counter unit 8-bit counter. Writing to the TCNT0 Register blocks (removes) the compare
match on the following timer clock. Modifying the counter (TCNT0) while the counter is running,
introduces a risk of missing a compare match between TCNT0 and the OCR0 Register.

##Timer Count Calculation

How we got this TCNT0 value?

```c
if (TCNT0 >= 200)
```

###Prescaler Timer Calculation

Timer Count Calculation for 10ms with 8MHz Crystal

![Alt text] (https://github.com/ganeshredcobra/Avr_Programming/blob/master/Timers/IMG/freq.jpg "Frequency")

![Alt text] (https://github.com/ganeshredcobra/Avr_Programming/blob/master/Timers/IMG/time.jpg "Time")

![Alt text] (https://github.com/ganeshredcobra/Avr_Programming/blob/master/Timers/IMG/TC.jpg "Timer Count")

