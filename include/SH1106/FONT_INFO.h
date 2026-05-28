#ifndef _FONT_INFO_H_
#define _FONT_INFO_H_

#include <stdint.h>

typedef struct
{
	uint8_t start_char;
	uint8_t end_char;
	const uint16_t (*font_char_descriptors)[3];
	const uint8_t* font_bitmap;
}FONT_INFO;

#endif
