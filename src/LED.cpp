#include "LED.h"

Led::Led(uint8_t pinoLed) : //* Dois pontos para inicialização
    pino(pinoLed),
    estadoLed(LOW),
    desligarLedTempo(false),
    desligarNoMomento(0),
    tempoAnteriorPiscar(0),
    tempoEspera(0),
    estadoPiscar(false),
    repeticoes(0)

{
    pinMode(pinoLed, OUTPUT);
}

void Led::ligarLed()
{
    estadoPiscar = false;
    estadoLed = HIGH;
    desligarLedTempo = false;
}

void Led::ligarLed(unsigned long tempoligado_ms)
{
    estadoLed = HIGH;
    desligarLedTempo = true;
    desligarNoMomento = millis() + tempoligado_ms;
}

void Led::desligarLed()
{
    estadoPiscar = false;
    estadoLed = HIGH;
    desligarLedTempo = false;
    estadoLed = LOW;
}

void Led::alternar()
{
    estadoLed = !estadoLed;
}

void Led::piscarLed()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estadoLed = HIGH;
    desligarLedTempo = false;
}

void Led::piscarLed(float frequencia)
{
    float tempo_ms = 500.0f / frequencia;
    estadoPiscar = true;
    tempoEspera = 500.0f / frequencia;
    tempoAnteriorPiscar = millis();
    estadoLed = HIGH;
    desligarLedTempo = false;
}

void Led::piscarLed(float frequencia, uint16_t repeticoes)
{
    float tempo_ms = 500.0f / frequencia;

    estadoPiscar = true;
    tempoEspera = 500.0f / frequencia;
    tempoAnteriorPiscar = millis();
    estadoLed = HIGH;
    this->repeticoes = repeticoes * 2;
    desligarLedTempo = false;
}

void Led::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estadoLed = !estadoLed;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estadoLed = LOW;
            }
        }
    }
}

bool Led::getEstado()
{
    return estadoLed;
}

void Led::setEstado(bool estadoLed)
{
    this->estadoLed = estadoLed;
    desligarLedTempo = false;
    estadoPiscar = false;
}

uint8_t Led::getPinoLed()
{
    return pino;
}

void Led::update()
{
    if (desligarLedTempo)
    {
        funcaoDesligamento();
    }

    if (estadoPiscar)
    {
        funcaoPiscar();
    }

    digitalWrite(pino, estadoLed);
}

void Led::funcaoDesligamento()
{
    if (millis() >= desligarNoMomento)
    {
        estadoLed = LOW;
        desligarLedTempo = false;
    }
}