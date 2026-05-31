#include "ui.h"

#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include "config.h"
#include "input.h"
#include "display.h"
#include "include/SH1106/FONT_courier_new_10pt_bold.h"

void wheel_diameter_select_menu(float* wheel_size){
    if(*wheel_size == 0)
        *wheel_size = DEFAULT_WHEEL_SIZE;
    
    uint8_t event = 1;
    clear_kb_state();
    
    while(1){
        // handle updates
        if(event){
            if(left_but_click)
                *wheel_size -= 0.1;
            if(right_but_click)
                *wheel_size += 0.1;
            if(center_but_click)
                return;

            char buff[15];
            snprintf(buff, sizeof(buff), "< %.1f >", *wheel_size);
                
            SH1106_I2C_DrawBoxFilled(0, 0, 127, 63, 0);

            SH1106_I2C_DrawString(WHEEL_SIZE_TEXT, 0, 0, courierNew_10ptFontInfo, 1);
            SH1106_I2C_DrawString(buff, 0, 12, courierNew_10ptFontInfo, 1);
            
            SH1106_I2C_UpdateDisplay();
        }
        
        // get user input updates
        _delay_ms(5);   // standby for clear interrupts
        event = handle_kb_event();
    }
}