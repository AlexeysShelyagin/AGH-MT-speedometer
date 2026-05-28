#ifndef _FONT_COURIER_NEW_18PT_
#define _FONT_COURIER_NEW_18PT_

#include "FONT_INFO.h"
#if defined(ESP8266)
	#include "user_interface.h"
	#include <ets_sys.h>
	#include <osapi.h>
#else
	#include <stdint.h>
	#include <stdlib.h>
#endif

/* Font data for Courier New 18pt */
extern const uint8_t courierNew_18ptBitmaps[];
extern const FONT_INFO courierNew_18ptFontInfo;
extern const uint16_t courierNew_18ptDescriptors[][3];

#endif
