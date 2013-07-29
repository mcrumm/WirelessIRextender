#include "JsonSerial.h"
#include "RFPacket.h"
#include "IRPacket.h"
#include "CommonProtocolEncoder.h"
#include "CommonProtocolDecoder.h"
#include "RFReceiver.h"
#include "RFTransmitter.h"
#include "IRLib.h"

IRPacket                irPacket;
RFPacket                rfPacket;
CommonProtocolEncoder   myEncoder(100);
CommonProtocolDecoder   myDecoder;
RFReceiver              rfReceiver(0);
RFTransmitter           rfTransmitter;
volatile unsigned int	cycleCount;
volatile unsigned long  payload;

int freeRam ()
{
  extern int __heap_start, *__brkval; 
  int v; 

  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void setup()
{
  delay(2000);
  Serial.begin(9600);
  rfTransmitter.setup(13);
  rfReceiver.start();
  Serial.println("Setup Complete");
}

void loop()
{
  payload = 0xFA1C;
    
  Serial.print("Origin Payload: ");
  Serial.println(payload);

  myEncoder.setCode(payload);
  myEncoder.encode(&rfPacket);

  //Transmit Packet
  rfTransmitter.send(&rfPacket, 1);

  // ...

  // Receive Packet
  myDecoder.decode(&rfPacket);
  myDecoder.fillPacket(&irPacket);

  Serial.print("IRPacket Payload: ");
  irPacket.printToSerial();

  Serial.println("-----------------------------------------------------------------");
}
