#ifndef CONFIG_H
#define CONFIG_H

#include <avr/io.h>

#define F_CPU 16000000UL


// ----------------- KEYBOARD SETUP ----------------------------

#define LEFT_BUT_PIN PD4
#define CENTER_BUT_PIN PD3
#define RIGHT_BUT_PIN PD2

#define LEFT_BUT_INT PCINT20        // PD4
#define CENTER_BUT_INT PCINT19      // PD3
#define RIGHT_BUT_INT PCINT18       // PD2

#define LEFT_BUT_INVERT 0
#define CENTER_BUT_INVERT 0
#define RIGHT_BUT_INVERT 0

// set port D for keyboard register
#define DDR_KB DDRD
#define PORT_KB PORTD
#define PIN_KB PIND
#define PCMSK_KB PCMSK2
#define PCIE_KB PCIE2

//#define BUT_FILTER_TIME 150

// -----------------------------------------------------------------





// ---------------------- SPEEDOMETER SETUP ------------------------

#define SPD_TRIG_PIN PD5
#define SPD_TRIG_INT PCINT21

#define SPD_TRIG_INVERT 1

#define DDR_SPD DDRD
#define PORT_SPD PORTD
#define PIN_SPD PIND
#define PCMSK_SPD PCMSK2
#define PCIE_SPD PCIE2

#define SPD_TRIG_FILTER_TIME 30

// -----------------------------------------------------------------





// ----------------------- WHEEL PARAMETERS ------------------------

#define WHEEL_SIZE_TO_CIRCUMFERENCE(size) size*25.4*3.14159
#define WHEEL_LEN_TO_KM(len) len / 1e6
#define CALC_KMH(dt, len) len * 3.6f / dt

#define DEFAULT_WHEEL_SIZE 26
#define MIN_WHEEL_SIZE 5
#define MAX_WHEEL_SIZE 50
#define MIN_SPEED 2.0f

static char WHEEL_SIZE_TEXT[] = "Your wheel size:";
#define WHEEL_SCROLL_DISP_TEXT "< %.1f\" >"

#define SPEED_DISP_TEXT "%.1f KMH"
#define DIST_DISP_TEXT "%.2f KM"

// -----------------------------------------------------------------





// --------------------------- EEPROM ------------------------------

#define WHEEL_SIZE_EEPROM_ADDR 0

// -----------------------------------------------------------------

#endif