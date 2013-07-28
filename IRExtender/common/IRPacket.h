#ifndef IRPACKET_H
#define IRPACKET_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class IRPacket
{
private:
	word				m_nTiming;
	unsigned long long	m_nData;

private:
	void				printData();

public:
	IRPacket();
	unsigned long long	getData();
	void				setData(unsigned long long nData);
	word				getTiming();
	void 				setTiming(word nTiming);
	void				printToSerial();
};

#endif