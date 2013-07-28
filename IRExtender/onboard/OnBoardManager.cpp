#include "OnBoardManager.h"

#include "Ninja.h"

#include "CommonProtocolDecoder.h"
#include "CommonProtocolEncoder.h"

#include "WT450ProtocolDecoder.h"

#include "arlecProtocolDecoder.h"
#include "arlecProtocolEncoder.h"

#include "HE330v2ProtocolDecoder.h"
#include "HE330v2ProtocolEncoder.h"

#include "OSv2ProtocolDecoder.h"


OnBoardManager::OnBoardManager()
{
	m_Decoders[0] = new CommonProtocolDecoder();
	m_Decoders[1] = new WT450ProtocolDecoder();
	m_Decoders[2] = new arlecProtocolDecoder();
	m_Decoders[3] = new HE330v2ProtocolDecoder();
	m_Decoders[4] = new OSv2ProtocolDecoder();

}

void OnBoardManager::setup()
{
	m_Transmitter.setup(TRANSMIT_PIN);

	m_Receiver.start();
}

void OnBoardManager::check()
{
	RFPacket*	pReceivedPacket = m_Receiver.getPacket();

	// Check for unhandled RF data first
	if(pReceivedPacket != NULL)
	{
		Decoder *decoder = properDecoder(pReceivedPacket);

		if(decoder != NULL)
		{

			NinjaPacket packet;

			decoder->fillPacket(&packet);

			packet.printToSerial();
		}

		// Purge 
		m_Receiver.purge();
	}

}

Decoder* OnBoardManager::properDecoder(RFPacket* packet)
{
	Decoder* result = NULL;

	for(int i = 0; i < NUM_DECODERS; i++)
	{
		Decoder *decoder = m_Decoders[i];
		bool canDecoderDecodeThePacket = decoder->decode(packet);
		packet->rewind();

		if(canDecoderDecodeThePacket)
		{
			result = decoder;
		}
	}

	return result;
}

void OnBoardManager::handle(NinjaPacket* pPacket)
{
	if(pPacket->getGuid() != 0)
		return;

	if(pPacket->getDevice() == ID_ONBOARD_RF)
	{
		m_Receiver.stop();

		char encoding = pPacket->getEncoding();

		switch (encoding)
		{
			case ENCODING_COMMON:
				m_encoder = new CommonProtocolEncoder(pPacket->getTiming());
				break;
			case ENCODING_ARLEC:
				m_encoder = new arlecProtocolEncoder(pPacket->getTiming());
				break;
			case ENCODING_HE330:
				m_encoder = new HE330v2ProtocolEncoder(pPacket->getTiming());
				break;	
		}

		m_encoder->setCode(pPacket->getData());
		m_encoder->encode(&m_PacketTransmit);

		m_Transmitter.send(&m_PacketTransmit, 5);

		m_Receiver.start();
	}
	
	if(pPacket->getDevice() == ID_ONBOARD_RF)
	{
		m_Receiver.stop();

		char encoding = pPacket->getEncoding();

		switch (encoding)
		{
			case ENCODING_COMMON:
				m_encoder = new CommonProtocolEncoder(pPacket->getTiming());
				break;
			case ENCODING_ARLEC:
				m_encoder = new arlecProtocolEncoder(pPacket->getTiming());
				break;
			case ENCODING_HE330:
				m_encoder = new HE330v2ProtocolEncoder(pPacket->getTiming());
				break;	
		}

		m_encoder->setCode(pPacket->getData());
		m_encoder->encode(&m_PacketTransmit);

		m_Transmitter.send(&m_PacketTransmit, 5);

		m_Receiver.start();
	}

	pPacket->setType(TYPE_ACK);
	pPacket->printToSerial();
}
