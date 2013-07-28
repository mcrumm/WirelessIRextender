#ifndef JSONSERIAL_H
#define JSONSERIAL_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "NinjaPacket.h"

class JsonSerial
{
private:
	char*			m_Buffer;
	
public:
	JsonSerial();

	void	setup(unsigned long nBaudRate);
	bool	read(NinjaPacket* pPacket);
	void	printHex(byte b);
};

extern JsonSerial jsonSerial;

#endif