/**
 * @file activity2.c
 * @author ramya name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include<util/delay.h>
#include"activity2.h"

/**
 * @brief initialising the adc
 * 
 */
void initADC()

{

    ADMUX=(1<<REFS0);
    ADCSRA|=(1<<ADEN)|(7<<ADPS0);
}
/**
 * @brief passing the channel 
 * 
 * @param ch any channel from  the c port
 * @return uint16_t the value read by the ADC
 */
uint16_t ReadADC(uint8_t ch)
{

    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    ADCSRA|=(1<<ADIF);
    return(ADC);
}