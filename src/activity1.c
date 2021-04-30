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
/**
 * @brief defining status of switch_1 is defined by considering the status of input hardware pin
 * @brief defining status of switch_2 is defined by considering the status of input hardware pin
 */

#define switch_1 !(PIND & (1 << PD0))
#define switch_2 !(PIND & (1 << PD1))
/**
 * @brief check if the driver is seated and the heater is on
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
