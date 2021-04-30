/**
 * @file activity1.c
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
#include"activity1.h"
#include "macrodef.h"

/**
 * @brief initalizes the peripherals
 * 
 */

void init_peripherial()
{
  // Direction of ports
  DDRD|=(1<<PWM_GEN_PIN);
  DDRB|=(1<<LED_PIN);
  // PULL-UP +5V for push-buttons
  PORTD=0b00000011;
}
/**
 * @brief checks if whether the seat is occupied by the driver and 
 * he had turned on the switches
 * 
 * @return uint8_t 
 */
uint8_t check_seatoccup()
{
// condition will turn to be true only when both switches are closed
  if ((switch_1) && (switch_2))
{
    return 1;
}
return 0;
}
