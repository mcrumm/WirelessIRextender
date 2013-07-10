Arduino based 434MHz Wireless IR Extender
Intended for use with, but not limited to, a NinjaBlock (NB).

Parts List:
(1) Ardweeny, $9.95 USD, (any arduino compatible microcontroller will do) http://www.makershed.com/product_p/mksb012.htm
(1) FTDI Adapter, $15.00 USD, (having this separate allows us to re-use it which will lower the cost if we are making more than one) http://www.makershed.com/FTDI_Friend_v1_0_p/mkad22.htm
(1) IR LED, $0.75 USD, http://www.adafruit.com/products/387
(1) IR Sensor, $1.95 USD, http://www.adafruit.com/products/157
(1) 434MHz RF Link Receiver, $4.95 USD, https://www.sparkfun.com/products/10532
(1) 434MHz RF Link Transmitter, $3.95 USD, https://www.sparkfun.com/products/10534

Proposed Libraries:
RF - https://code.google.com/p/rc-switch/ this is used by NinjaBlock so I thought it would make sense to utilize the same one for consistency.
IR - https://github.com/cyborg5/IRLib
Alternative Libraries:
RF - http://www.airspayce.com/mikem/arduino/VirtualWire/index.html with a visual guide here, http://www.pjrc.com/teensy/td_libs_VirtualWire.html
IR - http://www.righto.com/2009/08/multi-protocol-infrared-remote-library.html which the above is based on

Capabilities:
Flowchart - https://plus.google.com/100877474955327466991/posts/XdTzDKRhvCU
1. Decode IR remotes and transmits each code via RF.
2. Receives codes via RF which will then be replayed using IR LED.
3. Compatible with NinjaBlock.

Progress:
2013-07-10: Right now I'm just testing components. I am able to receive RF signals and decode them as binary utilizing the same library I see in the NB repository, https://code.google.com/p/rc-switch/ with included test sketch. I am also able to decode and replay IR signals using https://github.com/cyborg5/IRLib.

Thoughts:
I want the Wireless IR Extender to remain simple. I want the IR codes to be stored in the NB code so that the arduino does not need to be updated each time a device is added.
As I posted here, http://forums.ninjablocks.com/index.php?p=/discussion/1392/wireless-ir-extender-lets-build-one
Similar project brought to my attention by xneo1, http://www.cooking-hacks.com/index.php/documentation/tutorials/control-hvac-infrared-devices-from-the-internet-with-ir-remote/

My Limitations:
I'm really no programmer. I've messed with arduinos and some wireless modules before but it has always been a lot of copy and pasting of code. I'm more concerned about being able to interface this device I create with the NB. I know they have done some great work with their documentation so when it comes time I hope I can figure it out. If not I'm hoping that the community will give me a hand.

I really think this could be cool as it will be more of a universal IR remote for the NinjaBlock.