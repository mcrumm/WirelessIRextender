#include "IRPacket.h"
#include "Ninja.h"

IRPacket::IRPacket()
{
  m_nData = 0;
}

unsigned long long IRPacket::getData()
{
	return m_nData;
}

void IRPacket::setData(unsigned long long nData)
{
	m_nData = nData;
}

word IRPacket::getTiming()
{
	return m_nTiming;
}

void IRPacket::setTiming(word nTiming)
{
	m_nTiming = nTiming;
}

void IRPacket::printToSerial()
{
  Serial.println((unsigned long)m_nData);
}
