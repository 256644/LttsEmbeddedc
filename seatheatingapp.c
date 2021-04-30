/**
 * @file main.c
 * @author ramya name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 
#include <avr/io.h>
#include<util/delay.h>
#include"activity1.h"
#include"activity2.h"
#include"activity3.h"
#include"activity4.h"

/**
 * @brief macro definition
 * 
 */
#define LED_PIN PB0
#define LED_PORT PORTB
#define PWM_GEN_PIN PD6
#define SETD 0b00000011
// OCR0A (16-bit register contains the converted value)
#define  PWM_GEN OCR0A
#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
/**
 * @brief initialising values
 * 
 */
void init_peripherial()
{
  // Direction of ports
  DDRD|=(1<<PWM_GEN_PIN);
  DDRB|=(1<<LED_PIN);
  // PULL-UP +5V for push-buttons
  PORTD=SETD;
  

}

int main(void)
{
// temp contains the temperature value that ADC renders
unsigned volatile temp;
/**
 * @brief call functionthat configures peripheral
 * 
 */
init_peripherial();
/**
 * @brief calling adc function which is initialised
 *  
 */
initADC();
/**
 * @brief Set the pulse width modultion registers
 * 
 */
set_pwm();
/**
 * @brief initialising uart communication
 * 
 */
USART_Init(MYUBRR);
while(1)
{
/**
 * @brief if the driver is seated and the heater is also on
 * 
 */
volatile uint8_t check=0;
check=check_seatoccup();
if(check)
{
    /**
     * @brief reading the temperature value
     * 
     */
    LED_PORT|=(1<<LED_PIN);
    temp=ReadADC(0);
      
      if((temp>=0 && temp<=200))
      {
        /**
         * @brief transmitting the temperature values
         * 
         */
        USARTWriteChar(20);
         PWM_GEN=52;
        _delay_ms(2000);

      }
      else if(temp>=210 && temp<=500)
      {
          USARTWriteChar(25);
          PWM_GEN=105;
        _delay_ms(2000);
      }
      else if(temp>=510 && temp<=700)
      {  
        USARTWriteChar(29); 
          PWM_GEN=179;
        _delay_ms(2000);  
      }
      else if(temp>=710 && temp<=1024)
      {
          USARTWriteChar(30);
            PWM_GEN=243;
        _delay_ms(2000);  
      }

}
/**
 * @brief if no driver is seated
 * 
 */

else
{


    LED_PORT&=~(1<<LED_PIN);
}

}

}
