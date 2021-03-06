#USART Explained

![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/UART/Img/USART_BlkDiag.png "Block Diagram")

##Registers

Register | Description
------------ | -------------
 UDR |USART Data Register 
 UCSRA | USART Control and status Register A
 UCSRB | USART Control and status Register B
 UCSRC | USART Control and status Register C
 UBRRH |USART Baud rate register High Byte
 UBRRL |USART Baud rate register Low Byte
 
##Code Explanation
###Init Function
```c
//Initialise UART: format 8 data bits, No parity, 1 stop bit
void uart_init(uint16_t baud)
{
    UCSRB = (1 << TXEN) | (1 << RXEN);
    UBRRH = (COMPUTE_BAUD(baud) >> 8) & 0xff;
    UBRRL = (COMPUTE_BAUD(baud)) & 0xff;
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}
```
 ![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/UART/Img/UCSRB.png "UCSRB")
 
* __Bit 7 – RXCIEn: RX Complete Interrupt Enable n__
Writing this bit to one enables interrupt on the RXCn Flag. A USART Receive Complete interrupt will be
generated only if the RXCIEn bit is written to one, the Global Interrupt Flag in SREG is written to one and the
RXCn bit in UCSRnA is set.
* __Bit 6 – TXCIEn: TX Complete Interrupt Enable n__
Writing this bit to one enables interrupt on the TXCn Flag. A USART Transmit Complete interrupt will be
generated only if the TXCIEn bit is written to one, the Global Interrupt Flag in SREG is written to one and the
TXCn bit in UCSRnA is set
```c
UCSRB = (1 << TXEN) | (1 << RXEN);
``` 
###Baud Rate Calculation
__Baud Rate registers__
![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/UART/Img/UBRR_H_L.png "UBRR_H_L")
__Baud Rate Calculation Equation__
![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/UART/Img/Baudrate_eq.png "Equation")

The Baud rate calculation is done by the ``` #define ```
```c
#define CPU_CLOCK	8000000		// 8 MHz clock is assumed
#define COMPUTE_BAUD(b) ((uint32_t)(CPU_CLOCK)/((uint32_t)(b)*16) - 1)
```
So for a baudrate of 38400 and 8Mhz crystal the caclculation will be like this ```((8000000)/(38400 x 16))-1)``` which is equal to decimal 12 or hex 0x0C.
Shifting those values to registers.
```c
UBRRH = (COMPUTE_BAUD(baud) >> 8) & 0xff;
UBRRL = (COMPUTE_BAUD(baud)) & 0xff;
```
So UBRRH = 0 and UBRRL = 0xC
###Control Register and 8 bits setting
```c
UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
```
 ![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/UART/Img/UCSRC.png "UCSRC")

* __Bit 7 – URSEL: Register Select__
This bit selects between accessing the UCSRC or the UBRRH Register. It is read as one when
reading UCSRC. The URSEL must be one when writing the UCSRC.

* __UCSZ bit selection for 8 bits__

 ![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/UART/Img/UCSZ.png "UCSZ")
 
 ###Transmit Function
 
 ```c
void uart_send_byte(uint8_t c)
{
    while( !(UCSRA & (1 <<UDRE) ) );
    UDR = c;
}
```
 ###Receive Function
 
 ```c
uint8_t uart_recv_byte(void)
{
    while( !(UCSRA & (1 <<RXC)) );
    return UDR;
}
```
![Alt text](https://github.com/ganeshredcobra/Avr_Programming/blob/master/UART/Img/UCSRA.png "UCSRA")

* __Bit 7 – RXC: USART Receive Complete__
This flag bit is set when there are unread data in the receive buffer and cleared when the receive
buffer is empty (that is, does not contain any unread data). If the receiver is disabled, the receive
buffer will be flushed and consequently the RXC bit will become zero. The RXC Flag can be
used to generate a Receive Complete interrupt (see description of the RXCIE bit).

* __Bit 5 – UDRE: USART Data Register Empty__
The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. If UDRE is
one, the buffer is empty, and therefore ready to be written. The UDRE Flag can generate a Data
Register empty Interrupt (see description of the UDRIE bit).
UDRE is set after a reset to indicate that the transmitter is ready.
