#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#include"activity3.h"
/**
 * @brief Set the pwm object
 * initalising the pwm value
 * 
 */
void set_pwm()
{
TCCR0A |=(1<<COM0A1)|(1<<WGM01)|(1<<WGM00);
TCCR0B|=(1<<CS00)|(1<<CS01);
}