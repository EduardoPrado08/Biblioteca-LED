#include <Arduino.h>
#include <LED.h>

/**
 * Mantém o LED ligado por 2000 milissegundos
 */

Led ledA(20);

void setup()
{
    ledA.ligarLed(2000);
}

void loop()
{
    ledA.update();
}