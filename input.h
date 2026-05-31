#ifndef INPUT_H
#define INPUT_H

#include <stdint.h>

extern uint8_t left_but_click;
extern uint8_t center_but_click;
extern uint8_t right_but_click;

void init_keyboard(void);
uint8_t handle_kb_event(void);
void clear_kb_state(void);

#endif