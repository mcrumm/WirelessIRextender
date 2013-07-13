/*
This is the first step in creating a Wireless Universal IR extender.
Currently it is only the FRIGIDAIRE A/C Unit as its data is entered manually.
*/
#include <IRLib.h>
#include <RCSwitch.h>

/* 
Define our emulated IR buttons, give them decimal values that link them to a RF signal
24 bit string 101111011101001000000000, where last 4 bits increment 
*/
#define FRIGIDAIRE_Power 12440064
#define FRIGIDAIRE_Timer 12440065
#define FRIGIDAIRE_FanUp 12440066
#define FRIGIDAIRE_FanDown 12440067
#define FRIGIDAIRE_Cool 12440068
#define FRIGIDAIRE_TempUp 12440069   //also timer up
#define FRIGIDAIRE_TempDown 12440070 //also timer down
#define FRIGIDAIRE_AutoFan 12440071
#define FRIGIDAIRE_FanOnly 12440072
#define FRIGIDAIRE_ES 12440073       //Energy Saver
#define FRIGIDAIRE_Sleep 12440074

#define ENABLE_Sniffer true  //debug output

RCSwitch myRFSwitch = RCSwitch(); //Create an instance of RCswitch
IRsend My_Sender;  //Instantiate IRsend class
int del = 500; //Delay value for end of loop

void setup() {
Serial.begin(9600);
myRFSwitch.enableReceive(0); //receiver on interrupt 0 => that is pin #2
}


void loop() {
  if (myRFSwitch.available()) {
  
    long RFvalue = myRFSwitch.getReceivedValue();

    if (RFvalue == 0) {
      Serial.print("Unknown encoding");
    }
    else {
    if (ENABLE_Sniffer) {
      Serial.print("Received ");
      Serial.print( RFvalue );
      Serial.print(" / ");
      Serial.print( myRFSwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( myRFSwitch.getReceivedProtocol() );
    }
    
    switch (RFvalue) {  // Decide which IR signal to send given the IR signal received
      case FRIGIDAIRE_Power:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_Timer:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_FanUp:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_FanDown:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_Cool:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_TempUp:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_TempDown:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_AutoFan:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_FanOnly:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_ES:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      case FRIGIDAIRE_Sleep:
        My_Sender.send(SONY,0xA8BCA,20); //Code Type, Code Value, Code Bit Length
        Serial.println("Sent FRIGIDAIRE_Power");
        break;
      } //switch

    } //else

  // Prepare for more input
  myRFSwitch.resetAvailable();
  } //if
  
  delay(del); //Slow the loop  
} //loop
