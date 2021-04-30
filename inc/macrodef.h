
/**
 * @brief macro definations
 * 
 */
#define LED_PORT PORTB
#define PWM_GEN_PIN PD6
#define LED_PIN PB0
#define  PWM_GEN OCR0A
#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1
/**
 * @brief defining status of switch_1 is defined by considering the status of input hardware pin
 * @brief defining status of switch_2 is defined by considering the status of input hardware pin
 */

#define switch_1 !(PIND & (1 << PD0))
#define switch_2 !(PIND & (1 << PD1))