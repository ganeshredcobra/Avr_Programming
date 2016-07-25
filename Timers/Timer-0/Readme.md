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
 
