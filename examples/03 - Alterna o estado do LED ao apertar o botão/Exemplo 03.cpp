#include <Arduino.h>
#include <LED.h>

/**
 * Alterna o estado do LED ao apertar o botão
 */

Led led(20);

const uint8_t pinBotao = 0;
void setup()
{
    pinMode(pinBotao, INPUT_PULLUP);
    led.desligarLed();
}

void loop()
{
    led.update();

    bool estadoAtualBotao = digitalRead(pinBotao);
    static bool estadoAnteriorBotao = HIGH;
    
    if(estadoAnteriorBotao && !estadoAtualBotao)
    {
        led.alternar();
    }
    estadoAnteriorBotao = estadoAtualBotao;
}