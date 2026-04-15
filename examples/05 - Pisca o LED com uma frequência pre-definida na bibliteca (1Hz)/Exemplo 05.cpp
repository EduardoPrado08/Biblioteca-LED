#include <Arduino.h>
#include <LED.h>

/**
 * Pisca o LED com uma frequência de 1 Hz
 */

Led led(20);


void setup()
{
    led.piscarLed();
}

void loop()
{
    led.update();
}