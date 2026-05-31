#ifndef CONFIG_H
#define CONFIG_H

#include <avr/io.h>

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

#endif