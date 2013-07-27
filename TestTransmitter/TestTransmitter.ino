/*
I wanted to setup another device (Nanode) that would simply send the 32bit
IR remote code over and over again. This way I can test my RF receiver.
*/
#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int led = 6;

void setup() {
  mySwitch.enableTransmit(3);  // Using Pin #3
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
}

void loop() {
  digitalWrite(led, LOW);   // turn the LED on to show we are about to transmit
  delay(1000);               // wait for a second
  digitalWrite(led, HIGH);    // turn the LED off
  mySwitch.send(12440064,24);
  delay(20000);  
}
