#include <avr/io.h>
#include<util/delay.h>
#include"activity1.h"
/**
 * @brief check if the driver is seated and the heater is on
 * 
 * @return uint8_t 
 */
uint8_t check_seating()
{

  if((!(PIND&(1<<PD0))) &&(!(PIND&(1<<PD1))))
{


    return 1;
}
return 0;
}
