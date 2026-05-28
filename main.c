#define F_CPU 16000000UL

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "include/SH1106/SH1106_I2C.h"


void _sh1106_i2c_init_function(void){
	TWSR0 = 0x00;
	TWBR0 = 72; // 100kHz @ 16MHz
	TWCR0 = (1 << TWEN);
}

void _sh1106_i2c_send_start_function(void){
	TWCR0 = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	while (!(TWCR0 & (1 << TWINT)));
}

void _sh1106_i2c_send_stop_function(void){
	TWCR0 = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void _sh1106_i2c_send_byte_function(uint8_t data){
	TWDR0 = data;

	TWCR0 = (1 << TWINT) | (1 << TWEN);

	while (!(TWCR0 & (1 << TWINT)));
}

void debug_printf(const char *fmt, ...){

}

void *os_zalloc(size_t size)
{
	return calloc(1, size);
}

void _sh1106_i2c_backend_init(void){
	_sh1106_i2c_init_function();
}



int main(void) {
	SH1106_I2C_SetDeviceAddress(SH1106_I2C_ADDRESS_1);
	SH1106_I2C_Init();
	SH1106_I2C_SetDisplayNormal();
	
	
    while(1)
    {
		for(uint8_t i = 0; i < 107; i++){
			SH1106_I2C_DrawBoxFilled(0, 0, 127, 63, 0);
			SH1106_I2C_DrawBoxFilled(i, 20, i+20, 50, 1);
			
			SH1106_I2C_UpdateDisplay();
			_delay_ms(5);
		}
    }
}