#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

extern volatile uint32_t __millis;

void init_millis_timer(void);
uint32_t millis();

#endif