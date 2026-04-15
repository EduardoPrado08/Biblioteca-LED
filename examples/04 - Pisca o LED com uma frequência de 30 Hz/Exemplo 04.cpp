#include<Arduino.h>
#include<LED.h>

/**
 * Pisca o LED com uma frequência de 30 Hz
 */

Led ledA(20);

void setup()
{
    ledA.piscarLed(30);
}

void loop()
{
    ledA.update();
}