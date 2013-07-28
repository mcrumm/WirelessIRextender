#ifndef ENCODER_H
#define ENCODER_H

#include "RFPacket.h"

class Encoder
{
public:
	virtual void encode(RFPacket* pPacket) = 0;
	virtual void setCode(unsigned long long nCode) = 0;
};

#endif