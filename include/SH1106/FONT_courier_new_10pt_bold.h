#ifndef _FONT_COURIER_NEW_10PT_BOLD_
#define _FONT_COURIER_NEW_10PT_BOLD_

#include "FONT_INFO.h"
#if defined(ESP8266)
	#include "user_interface.h"
	#include <ets_sys.h>
	#include <osapi.h>
#else
	#include <stdint.h>
	#include <stdlib.h>
#endif

// Font data for Courier New 12pt
extern const uint8_t courierNew_10ptBitmaps[];
extern const FONT_INFO courierNew_10ptFontInfo;
extern const uint16_t courierNew_10ptDescriptors[][3];

#endif

