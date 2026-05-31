#ifndef CONFIG_H
#define CONFIG_H

#include <avr/io.h>

#define F_CPU 16000000UL



#define LEFT_BUT_PIN PD4
#define CENTER_BUT_PIN PD3
#define RIGHT_BUT_PIN PD2

#define LEFT_BUT_INT PCINT20        // PD4
#define CENTER_BUT_INT PCINT19      // PD3
#define RIGHT_BUT_INT PCINT18       // PD2

// set port D for keyboard register
#define DDR_KB DDRD
#define PORT_KB PORTD
#define PIN_KB PIND
#define PCMSK_KB PCMSK2
#define PCIE_KB PCIE2

//#define BUT_FILTER_TIME 150


#define DEFAULT_WHEEL_SIZE 26
#define MIN_WHEEL_SIZE 5
#define MAX_WHEEL_SIZE 50
static char WHEEL_SIZE_TEXT[] = "Your wheel size:";


#define WHEEL_SIZE_EEPROM_ADDR 0

#endif