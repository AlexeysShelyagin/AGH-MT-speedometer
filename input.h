#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>

extern uint8_t left_but_click;
extern uint8_t center_but_click;
extern uint8_t right_but_click;

void init_keyboard(void);
void handle_kb_event(void);

#endif