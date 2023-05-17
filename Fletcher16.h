// Fletcher16.h

#pragma once
#ifndef _FLETCHER16_h
#define _FLETCHER16_h

#include <stdint.h>

class Fletcher16
{
public:
	static uint16_t GetChecksum(const uint8_t* data, size_t len);
	static uint16_t GetChecksumAppendCheckBytes(uint8_t* data, size_t len);
	static uint16_t GetCheckBytes(const uint8_t* data, size_t len);
	static uint16_t GetAndAppendCheckBytes(uint8_t* data, size_t len);

	union CheckBytes {
		uint16_t bothBytes16;
		uint8_t  checkbyte8[2];
	};
};


#endif


