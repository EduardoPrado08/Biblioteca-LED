#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado, piscar continuamente e piscar por quantidade definida.
 *
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
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

    /**
     * @brief Processa a lógica de piscada do LED.
     */
    void funcaoPiscar();

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoDesligamento();

public:
    /**
     * @brief Constroi um objeto LED.
     * @param pin Número do pino digital onde o LED está conectado.
     */
    Led(uint8_t pinoLed);

    /**
     * @brief Liga o LED continuamente.
     */
    void ligarLed();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado_ms Tempo, em milissegundos, que o LED ficará ligado.
     */
    void ligarLed(unsigned long tempoLigado_ms);

    /**
     * @brief Desliga o LED e cancela os modos automáticos.
     */
    void desligarLed();

    /**
     * @brief Inicia piscada contínua em 1Hz.
     */
    void piscarLed();

    /**
     * @brief Pisca o LED com uma frequencia definida.
     * @param frequencia Frequência da piscada em Hz.
     */
    void piscarLed(float frequencia);

    /**
     * @brief Pisca o LED com uma quantidade e frequencia definida.
     * @param frequencia Frequência da piscada em Hz.
     * @param repeticoes Quantidade piscadas completas.
     */
    void piscarLed(float frequencia, uint16_t repeticoes);

    /**
     * @brief Retorna o estado do LED.
     */
    bool getEstado();

    /**
     * @brief Define o estado do LED e cancela funções automáticas.
     * @param estadoLed Estado do LED (True para ligado e False para desligado).
     */
    void setEstado(bool estadoLed);

    /**
     * @brief Retorna o pino do LED.
     */
    uint8_t getPinoLed();

    /**
     * @brief Altera o nível lógico do LED.
     */
    void alternar();

    /**
     * @brief Atualiza o estado do LED.
     */
    void update();
};

#endif