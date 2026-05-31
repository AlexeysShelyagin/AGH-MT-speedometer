#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdlib.h>
#include <avr/io.h>
#include "include/SH1106/SH1106_I2C.h"

void _sh1106_i2c_init_function(void);
void _sh1106_i2c_send_start_function(void);
void _sh1106_i2c_send_stop_function(void);
void _sh1106_i2c_send_byte_function(uint8_t data);
void _sh1106_i2c_backend_init(void);

void debug_printf(const char *fmt, ...);
void os_printf(const char *fmt, ...);
void *os_zalloc(size_t size);

#endif