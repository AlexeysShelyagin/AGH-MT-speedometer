#ifndef _PATTERN_8x8_ASCII_H_
#define _PATTERN_8x8_ASCII_H_

#include "FONT_INFO.h"
#if defined(ESP8266)
	#include "user_interface.h"
	#include <ets_sys.h>
	#include <osapi.h>
#else
	#include <stdint.h>
	#include <stdlib.h>
#endif

// Pattern data
extern const uint8_t _8x8_asciiBitmaps[];
extern const FONT_INFO _8x8_asciiBitmapsFontInfo;

#endif
