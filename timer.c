#include "timer.h"

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint32_t millis = 0;
uint8_t millis_initialized = 0;

void init_millis_timer(void){
    if(millis_initialized)
        return;
    millis_initialized = 1;

    TCCR0A = (1 << WGM01);
    TCCR0B = (1 << CS01) | (1 << CS00);
    OCR0A = 249;
    TIMSK0 = (1 << OCIE0A);
}

ISR(TIMER0_COMPA_vect){
    millis++;
}