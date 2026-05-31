#include "eeprom_data.h"

#include <stdio.h>
#include <avr/eeprom.h>
#include <math.h>
#include "config.h"

float load_wheel_size(){
	float wheel_size = eeprom_read_float((float*) WHEEL_SIZE_EEPROM_ADDR);

	if(isnan(wheel_size) || wheel_size < MIN_WHEEL_SIZE || wheel_size > MAX_WHEEL_SIZE){
		wheel_size = DEFAULT_WHEEL_SIZE;
		eeprom_update_float((float*) WHEEL_SIZE_EEPROM_ADDR, wheel_size);
	}

    return wheel_size;
}

void save_wheel_size(float wheel_size){
    eeprom_update_float((float*) WHEEL_SIZE_EEPROM_ADDR, wheel_size);
}