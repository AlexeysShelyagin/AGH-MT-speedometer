#ifndef _FONT_WHITE_RABBIT_36PT_BOLD_
#define _FONT_WHITE_RABBIT_36PT_BOLD_

#include "FONT_INFO.h"
#if defined(ESP8266)
	#include "user_interface.h"
	#include <ets_sys.h>
	#include <osapi.h>
#else
	#include <stdint.h>
	#include <stdlib.h>
#endif

// Font data for White Rabbit 36pt
extern const uint8_t whiteRabbit_36ptBitmaps[];
extern const FONT_INFO whiteRabbit_36ptFontInfo;
extern const uint16_t whiteRabbit_36ptDescriptors[][3];

#endif
