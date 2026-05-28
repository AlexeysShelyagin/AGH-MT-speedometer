#ifndef _FONT_MENLO_10PT_
#define _FONT_MENLO_10PT_

#include "FONT_INFO.h"
#if defined(ESP8266)
	#include "user_interface.h"
	#include <ets_sys.h>
	#include <osapi.h>
#else
	#include <stdint.h>
	#include <stdlib.h>
#endif

// Font data for Menlo 11pt
extern const uint8_t menlo_10ptBitmaps[];
extern const FONT_INFO menlo_10ptFontInfo;
extern const uint16_t menlo_10ptDescriptors[][3];

#endif
