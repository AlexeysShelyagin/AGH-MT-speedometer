#include "PATTERN_8x8_ascii.h"

//
//  Pattern data for 8x8 ascii (ascii code 176+)
//	8x8 bits
//

const uint8_t _8x8_asciiBitmaps[] =
{
	//ASCII CODE 176
	0x00,
	0xAA,
	0x00,
	0x55,
	0x00,
	0xAA,
	0x00,
	0x55,

	//ASCII CODE 177
	0xAA,
	0x55,
	0xAA,
	0x55,
	0xAA,
	0x55,
	0xAA,
	0x55,

	//ASCII CODE 178
	0xFF,
	0x55,
	0xFF,
	0xAA,
	0xFF,
	0x55,
	0xFF,
	0xAA
};

// Font information for  8x8 ascii
const FONT_INFO _8x8_asciiBitmapsFontInfo =
{
	176, //  Start character
	178, //  End character
	NULL, //  Character descriptor array
	_8x8_asciiBitmaps, //  Character bitmap array
};

