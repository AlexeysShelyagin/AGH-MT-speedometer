#define F_CPU 16000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "display.h"
#include "include/SH1106/FONT_courier_new_10pt_bold.h"

#include "input.h"

char test_str[] = "12345ABCD";

int main(void) {
	SH1106_I2C_SetDeviceAddress(SH1106_I2C_ADDRESS_1);
	SH1106_I2C_Init();
	SH1106_I2C_SetDisplayNormal();

	init_keyboard();
	
	
    while(1)
    {
		for(uint8_t i = 0; i < 107; i++){
			SH1106_I2C_DrawBoxFilled(0, 0, 127, 63, 0);
			
			char buttons_txt[3];

			handle_kb_event();
			buttons_txt[0] = left_but_click + '0';
			buttons_txt[1] = center_but_click + '0';
			buttons_txt[2] = right_but_click + '0';

			SH1106_I2C_DrawString(buttons_txt, 0, 0, courierNew_10ptFontInfo, 1);
			
			
			SH1106_I2C_UpdateDisplay();
			_delay_ms(5);
		}
    }
}