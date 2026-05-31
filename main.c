#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "config.h"
#include "display.h"
#include "include/SH1106/FONT_courier_new_10pt_bold.h"

#include "input.h"
#include "timer.h"

uint8_t val = 127;

int main(void) {
	SH1106_I2C_SetDeviceAddress(SH1106_I2C_ADDRESS_1);
	SH1106_I2C_Init();
	SH1106_I2C_SetDisplayNormal();

	init_keyboard();
	
	
    while(1)
    {
		for(uint8_t i = 0; i < 107; i++){
			SH1106_I2C_DrawBoxFilled(0, 0, 127, 63, 0);
			
			handle_kb_event();
			if(left_but_click)
				val--;
			if(right_but_click)
				val++;
			if(center_but_click)
				val = 127;

			char buff[15];
			snprintf(buff, sizeof(buff), "%d", val);

			SH1106_I2C_DrawString(buff, 0, 0, courierNew_10ptFontInfo, 1);
			
			
			SH1106_I2C_UpdateDisplay();
			_delay_ms(5);
		}
    }
}