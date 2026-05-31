#define F_CPU 16000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#include "display.h"
#include "include/SH1106/FONT_courier_new_10pt_bold.h"

char test_str[] = "12345ABCD";

int main(void) {
	SH1106_I2C_SetDeviceAddress(SH1106_I2C_ADDRESS_1);
	SH1106_I2C_Init();
	SH1106_I2C_SetDisplayNormal();
	
	
    while(1)
    {
		for(uint8_t i = 0; i < 107; i++){
			SH1106_I2C_DrawBoxFilled(0, 0, 127, 63, 0);
			
			SH1106_I2C_DrawBoxFilled(i, 20, i+20, 50, 1);

			SH1106_I2C_DrawString(test_str, 0, 0, courierNew_10ptFontInfo, 1);
			
			
			SH1106_I2C_UpdateDisplay();
			_delay_ms(5);
		}
    }
}