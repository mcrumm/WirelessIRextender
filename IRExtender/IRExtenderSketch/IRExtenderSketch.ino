#include "JsonSerial.h"
#include "NinjaPacket.h"
#include "OnBoardManager.h"
#include "RFPacket.h"

#include "CommonProtocolEncoder.h"
#include "CommonProtocolDecoder.h"

#include "IRLib.h"

OnBoardManager  onBoardManager;
NinjaPacket     ninjaPacket;
volatile unsigned int	cycleCount;

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
  onBoardManager.setup();
  Serial.println("Setup Complete");
}

void loop()
{
  // 1. Check for serial data
  if(jsonSerial.read(&ninjaPacket))
  {
    if(ninjaPacket.getGuid() == 0)
		onBoardManager.handle(&ninjaPacket);
		
    Serial.print("G=");
    Serial.println(ninjaPacket.getGuid());
    Serial.print("D=");
    Serial.println(ninjaPacket.getDevice());
//    Serial.print("DA=");
//    Serial.println(ninjaPacket.getData());
    Serial.print("Ram=");
    Serial.println(freeRam()); 
  }
  
  
  // 3. Check onboard components for incoming data
  onBoardManager.check();

}
