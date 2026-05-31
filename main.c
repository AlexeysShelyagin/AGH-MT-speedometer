#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "config.h"
#include "display.h"
#include "include/SH1106/FONT_courier_new_10pt_bold.h"
#include "input.h"
#include "timer.h"
#include "ui.h"
#include "eeprom_data.h"

float wheel_size = 0;

int main(void) {
	SH1106_I2C_SetDeviceAddress(SH1106_I2C_ADDRESS_1);
	SH1106_I2C_Init();
	SH1106_I2C_SetDisplayNormal();

	init_keyboard();

	wheel_size = load_wheel_size();
	
	
    while(1)
    {	
		handle_kb_event();
		if(center_but_click){
			wheel_diameter_select_menu(&wheel_size);
			save_wheel_size(wheel_size);
		}

		char buff1[10], buff2[10];
		snprintf(buff1, sizeof(buff1), "%d", (int)__millis);
		snprintf(buff2, sizeof(buff2), "%.1f", wheel_size);


		SH1106_I2C_DrawBoxFilled(0, 0, 127, 63, 0);

		SH1106_I2C_DrawString(buff1, 0, 0, courierNew_10ptFontInfo, 1);
		SH1106_I2C_DrawString(buff2, 0, 30, courierNew_10ptFontInfo, 1);
		
		SH1106_I2C_UpdateDisplay();
		_delay_ms(5);
    }
}