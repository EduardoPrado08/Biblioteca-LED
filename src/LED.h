#ifndef LED_h
#define LED_h

#include <Arduino.h>

// MÉTODOS - AÇÕES DO OBJETO
// PROPRIEDADES - CARACTERÍSTICAS DO OBJETO

class Led
{
private:
    // ENCAPSULAMENTO
    uint8_t pino;
    bool estadoLed;
    bool desligarLedTempo;
    uint32_t desligarNoMomento;
     
    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;
   
    void funcaoPiscar();
    void funcaoDesligamento();

public:
    // CONSTRUTOR
    Led(uint8_t pinoLed);

    void ligarLed();
    void ligarLed(unsigned long tempoLigado_ms);

    void desligarLed();

    void piscarLed();
    void piscarLed(float frequencia);
    void piscarLed(float frequencia, uint16_t repeticoes);

    // GETTERS E SETTERS
    bool getEstado();
    void setEstado(bool estadoLed);

    uint8_t getPinoLed();

    void alternar();

    void update();
};

#endif