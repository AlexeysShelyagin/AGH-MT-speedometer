#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void init_millis_timer(void);

extern volatile uint32_t millis;

#endif