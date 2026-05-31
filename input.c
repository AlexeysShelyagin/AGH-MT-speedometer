#include "input.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "timer.h"

volatile uint8_t port_prev_state;
volatile uint8_t kb_event_flag = 0;
volatile uint8_t kb_event[3] = {0};

uint8_t left_but_click = 0;
uint8_t center_but_click = 0;
uint8_t right_but_click = 0;

void init_keyboard(void){
    cli();

    DDR_KB &= ~(1 << LEFT_BUT_PIN);         // Set input mode
    //PORT_KB |= (1 << LEFT_BUT_PIN);       // Enable pull-up
    DDR_KB &= ~(1 << CENTER_BUT_PIN);
    //PORT_KB |= (1 << CENTER_BUT_PIN);
    DDR_KB &= ~(1 << RIGHT_BUT_PIN);
    //PORT_KB |= (1 << RIGHT_BUT_PIN);

    // Enable PCINT for pin
    PCMSK_KB |= (1 << LEFT_BUT_INT);
    PCMSK_KB |= (1 << CENTER_BUT_INT);
    PCMSK_KB |= (1 << RIGHT_BUT_INT);

    // Enable PCINT group for PCIE_KB
    PCICR |= (1 << PCIE_KB);

    port_prev_state = PIN_KB;

    init_millis_timer();

    sei();
}

void handle_kb_event(void){
    if(kb_event_flag){
        left_but_click = kb_event[0];
        center_but_click = kb_event[1];
        right_but_click = kb_event[2];

        kb_event[0] = kb_event[1] = kb_event[2] = 0;
    }
    else
        left_but_click = center_but_click = right_but_click = 0;
    
    kb_event_flag = 0;  // mark event as handled
}


ISR(PCINT2_vect){
    uint8_t changed = PIN_KB ^ port_prev_state;

    if(changed & (1 << LEFT_BUT_PIN)){  // if state of button changed
        kb_event[0] = (PIN_KB >> LEFT_BUT_PIN) & 1;
        if(kb_event[0])
            kb_event_flag = 1;
    }
    if(changed & (1 << CENTER_BUT_PIN)){
        kb_event[1] = (PIN_KB >> CENTER_BUT_PIN) & 1;
        if(kb_event[1])
            kb_event_flag = 1;
    }
    if(changed & (1 << RIGHT_BUT_PIN)){
        kb_event[2] = (PIN_KB >> RIGHT_BUT_PIN) & 1;
        if(kb_event[2])
            kb_event_flag = 1;
    }

    port_prev_state = PIN_KB;
}