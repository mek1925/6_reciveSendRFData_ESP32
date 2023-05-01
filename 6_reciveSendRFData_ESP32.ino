/*
  Simple example for receiving

  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup()
{
    Serial.begin(9600);
    mySwitch.enableReceive(0); // Receiver on interrupt 0 => that is pin #2
    Serial.println("Start SRX882 RF receiver.... ");
}

void loop()
{
    if (mySwitch.available())
    {
        Serial.print("Received ");
        Serial.print(mySwitch.getReceivedValue());
        Serial.print(" / ");
        Serial.print(mySwitch.getReceivedBitlength());
        Serial.print("bit ");
        Serial.print("Protocol: ");
        Serial.println(mySwitch.getReceivedProtocol());

        mySwitch.resetAvailable();
    }
}
