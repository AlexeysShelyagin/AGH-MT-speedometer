#include "display.h"

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

void os_printf(const char *fmt, ...){

}

void *os_zalloc(size_t size){
	return calloc(1, size);
}

void _sh1106_i2c_backend_init(void){
	_sh1106_i2c_init_function();
}