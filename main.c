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
float wheel_len;

int main(void) {
	SH1106_I2C_SetDeviceAddress(SH1106_I2C_ADDRESS_1);
	SH1106_I2C_Init();
	SH1106_I2C_SetDisplayNormal();
	
	wheel_size = load_wheel_size();
	wheel_len = WHEEL_SIZE_TO_CIRCUMFERENCE(wheel_size);

	init_millis_timer();
	init_keyboard();
	init_spd_trig(&wheel_len);

	
    while(1){
		handle_kb_event();
		if(center_but_click){
			wheel_diameter_select_menu(&wheel_size);
			save_wheel_size(wheel_size);
			wheel_len = WHEEL_SIZE_TO_CIRCUMFERENCE(wheel_size);
		}

		render_speedometer_menu((get_speed() < MIN_SPEED) ? 0.0f : get_speed(), get_dist());

		_delay_ms(10);
    }
}