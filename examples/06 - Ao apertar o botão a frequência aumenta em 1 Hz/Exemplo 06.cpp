#include <Arduino.h>
#include <LED.h>

/**
 * Eleva a frequência do LED de 1 em 1 Hz a cada vez que o botão é apertado, e imprime esse número
 */

Led led(20);

const uint8_t pinBotao = 0;
void setup()
{
    pinMode(pinBotao, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop()
{
    static int VezesApertado = 0;

    bool estadoAtualBotao = digitalRead(pinBotao);
    static bool estadoAnteriorBotao = HIGH;
    
    if(estadoAnteriorBotao && !estadoAtualBotao)
    {
        VezesApertado++;
        Serial.println(VezesApertado); 
        led.piscarLed(VezesApertado); 
    }
    estadoAnteriorBotao = estadoAtualBotao;
   
    led.update();
}