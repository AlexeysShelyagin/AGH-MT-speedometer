#ifndef _FONT_ROLANDE_36PT_
#define _FONT_ROLANDE_36PT_

#include "FONT_INFO.h"
#if defined(ESP8266)
	#include "user_interface.h"
	#include <ets_sys.h>
	#include <osapi.h>
#else
	#include <stdint.h>
	#include <stdlib.h>
#endif

// Font data for Rolande 36pt
extern const uint8_t rolande_36ptBitmaps[];
extern const FONT_INFO rolande_36ptFontInfo;
extern const uint16_t rolande_36ptDescriptors[][3];

#endif
