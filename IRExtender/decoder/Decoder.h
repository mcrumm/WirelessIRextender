#ifndef DECODER_H
#define DECODER_H

#include "RFPacket.h"
#include "IRPacket.h"

class Decoder
{
public:
	virtual boolean decode(RFPacket* pPacket) = 0;
	virtual void	fillPacket(IRPacket* pPacket) = 0;
};

#endif