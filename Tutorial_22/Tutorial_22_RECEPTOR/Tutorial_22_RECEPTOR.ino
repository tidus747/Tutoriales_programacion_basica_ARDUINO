#include <VirtualWire.h>
 
const int dataPin = 9;
const int ledPin = 12;
 
void setup()
{
    vw_setup(2000);
    vw_set_rx_pin(dataPin);
    vw_rx_start();
    
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, true);
    delay(300);
    digitalWrite(ledPin, false);
}
 
void loop()
{
    uint8_t data;
    uint8_t dataLength=1;
 
    if (vw_get_message(&data,&dataLength))
    {
        if((char)data=='a')
        {
            digitalWrite(ledPin, true);
        }
        else if((char)data=='b')
        {
            digitalWrite(ledPin, false);
        }            
    }
}
