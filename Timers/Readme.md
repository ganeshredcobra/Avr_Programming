#Timers Explained

In AVR, timers are of two types: 8-bit and 16-bit timers. In an 8-bit timer, the register used is 8-bit wide whereas in 16-bit timer, the register width is of 16 bits. This means that __the 8-bit timer is capable of counting 2^8=256 steps from 0 to 255__ .Similarly __a 16 bit timer is capable of counting 2^16=65536 steps from 0 to 65535__.Due to this feature, timers are also known as counters.Once they reach their MAX value it returns to its initial value of zero. We say that the __timer/counter overflows__.

In ATMEGA32, we have three different kinds of timers:
* TIMER0 – 8-bit timer
* TIMER1 – 16-bit timer
* TIMER2 – 8-bit timer

Timers runs parallel to the CPU and there is no CPU’s intervention, which makes the timer quite accurate.
