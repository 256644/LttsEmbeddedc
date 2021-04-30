#include <avr/io.h>
/**
 * @file activity4.c
 * @author ramya name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<avr/interrupt.h>
#include<util/delay.h>
#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
/**
 * @brief initialising the USART
 * 
 * @param ubrr 
 */
void USART_Init(unsigned int ubrr)
{
/*Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
/*Enable receiver and transmitter */
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 2stop bit */
UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}
/*
char USARTReadChar()
{
    // Wait until data is available

    while(!(UCSR0A & (1<<RXC0)))
    {
        //Do nothing
    }

    return UDR0;
}
*/
void USARTWriteChar(unsigned int data)
{
/* Wait for empty transmit buffer */
while (!(UCSR0A & (1<<UDRE0)))
;
/* Put data into buffer, sends the data */
UDR0 = data;
}