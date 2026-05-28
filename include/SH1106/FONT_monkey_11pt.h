#ifndef FONT_MONKEY_11PT_
#define FONT_MONKEY_11PT_

#include "FONT_INFO.h"
#if defined(ESP8266)
	#include "user_interface.h"
	#include <ets_sys.h>
	#include <osapi.h>
#else
	#include <stdint.h>
	#include <stdlib.h>
#endif

/* Font data for Monkey 11pt */
extern const uint8_t monkey_11ptBitmaps[];
extern const FONT_INFO monkey_11ptFontInfo;
extern const uint16_t monkey_11ptDescriptors[][3];

#endif
