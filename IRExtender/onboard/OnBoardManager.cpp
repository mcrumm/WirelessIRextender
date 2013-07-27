#include "OnBoardManager.h"

#include "../common/Ninja.h"

#include "../decoder/CommonProtocolDecoder.h"
#include "../encoder/CommonProtocolEncoder.h"


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
		bool bDecodeSuccessful = false;
		m_nLastDecode = -1;

		for(int i = 0; i < NUM_DECODERS; i++)
		{
			if(m_Decoders[i]->decode(pReceivedPacket))
			{
				m_nLastDecode = i;

				bDecodeSuccessful = true;
			}
			pReceivedPacket->rewind();
		}

	/*	if(bDecodeSuccessful)
		{
			// Blink stat LED to show activity
			leds.blinkStat();

			NinjaPacket packet;
			
			m_Decoders[m_nLastDecode]->fillPacket(&packet);
			
			packet.printToSerial();
		}
	*/
		// Purge 
		m_Receiver.purge();
	}
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
		}
		
		if(pPacket->dataInArray))
			m_encoder->setCode(pPacket->getDataArray());
		else 
			m_encoder->setCode(pPacket->getData());
			
		m_encoder->setCode(pPacket->getData());
		m_encoder->encode(&m_PacketTransmit);
		
		m_Transmitter.send(&m_PacketTransmit, 5);

		m_Receiver.start();
	}

	pPacket->setType(TYPE_ACK);
	pPacket->printToSerial();
}