#include <Arduino.h>
#include <LED.h>

/**
 * Pisca o LED com a frequência de 3Hz 15 vezes
 */

Led led(20);


void setup()
{

    led.piscarLed(3, 15);
}

void loop()
{
    led.update();
}