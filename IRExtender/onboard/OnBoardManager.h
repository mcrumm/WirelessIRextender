#ifndef ONBOARDMANAGER_H
#define ONBOARDMANAGER_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "Decoder.h"
#include "Encoder.h"
#include "RFPacket.h"
#include "RFReceiver.h"
#include "RFTransmitter.h"

#define NUM_DECODERS	5

class OnBoardManager
{
private:
	RFReceiver		m_Receiver;
	RFTransmitter	m_Transmitter;
	RFPacket		m_PacketTransmit;

	Decoder*		m_Decoders[NUM_DECODERS];
	Encoder*			m_encoder;

	Decoder* properDecoder(RFPacket* packet);

public:
	OnBoardManager();

	void	setup();
	void	check();

	void	handle(NinjaPacket* pPacket);
};

#endif