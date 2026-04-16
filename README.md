# 💡 Biblioteca LED (Arduino/ESP32)

Biblioteca C++ orientada a objetos para o controlo de LEDs em sistemas embebidos. Desenvolvida para oferecer uma interface de alto nível e **não-bloqueante**, permitindo a gestão de efeitos luminosos sem interromper o fluxo principal do processador.

O diferencial desta biblioteca é a sua **lógica de estado determinística**: qualquer novo comando sobrepõe o estado anterior, garantindo que o hardware responda sempre à última intenção do programador.

---

## ✨ Funcionalidades

* **Processamento Assíncrono:** Utiliza `millis()` internamente, eliminando o uso de `delay()`.
* **Modo Piscar Inteligente:** Controlo por frequência (Hz) com suporte a número finito de repetições.
* **Temporização (Auto-off):** Função de ativação por tempo determinado com desligamento automático.
* **Gestão de Conflitos:** Máquina de estados interna que reseta processos automáticos ao receber comandos manuais.
* **Escalabilidade:** Código encapsulado que permite o controlo individual de múltiplos LEDs de forma simples.

---

## 🛠️ Tecnologias e Conceitos

* **C++ (Arduino SDK):** Utilização de listas de inicialização e otimização de memória.
* **Orientação a Objetos (POO):** Encapsulamento completo de pinos e estados.
* **Máquina de Estados:** Lógica interna para alternância entre modos estático, temporizado e intermitente.

---

## 📂 Estrutura de Métodos

| Método | Parâmetros | Descrição |
| :--- | :--- | :--- |
| **`ligar()`** | - | Ativa o LED continuamente. |
| **`ligar(ms)`** | `uint32_t ms` | Ativa o LED por um período e desliga após o tempo. |
| **`desligar()`** | - | Desativa o LED e interrompe qualquer ciclo em curso. |
| **`alternar()`** | - | Inverte o estado atual do LED (**Toggle**). |
| **`piscar(freq)`** | `float freq` | Inicia o modo piscar contínuo na frequência em Hz. |
| **`piscar(freq, n)`** | `float freq, int n` | Pisca na frequência definida por **n** vezes e para. |
| **`update()`** | - | Processa os timers e atualiza o estado físico (deve estar no `loop`). |

---

## 📂 Estrutura do Repositório

* **`src/`**: Contém os ficheiros fonte (`LED.h` e `LED.cpp`).
* **`examples/`**: Demonstrações de implementação prática.
* **`library.json`**: Configurações para PlatformIO e Gestor de Bibliotecas.
* **`LICENSE`**: Termos de uso da biblioteca.

---
> **Aviso:** A execução correta de todas as funções temporizadas depende da chamada constante do método `.update()` dentro da função principal de loop do seu firmware.
