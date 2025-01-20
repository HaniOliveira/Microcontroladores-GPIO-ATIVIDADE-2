#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"

// Definições dos pinos
#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12
#define BUZZER 21 // Pino do buzzer

// Função para desligar todos os LEDs
void turn_off_leds()
{
    // Coloca os pinos dos LEDs em estado baixo (desligado)
    gpio_put(LED_RED, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
}

// Função para configurar os GPIOs
void setup_gpio()
{
    // Configurar LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    // Configurar buzzer como saída
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    // Inicializar todos os LEDs desligados
    turn_off_leds();

    // Garantir que o buzzer esteja desligado
    gpio_put(BUZZER, 0);
}

// Função para emitir som no buzzer
void buzz_sound()
{
    // Gera um som pulsando o buzzer por 500 ms
    printf("Emitindo som no buzzer.\n");
    for (int i = 0; i < 500; i++)
    {
        gpio_put(BUZZER, 1); // Liga o buzzer
        sleep_us(1000);      // Aguarda 1 ms
        gpio_put(BUZZER, 0); // Desliga o buzzer
        sleep_us(1000);      // Aguarda 1 ms
    }
}

// Função para processar comandos recebidos
void process_command(char command_)
{
    if (command_ == 'r')
    {
        // Liga o LED vermelho e apaga os outros
        gpio_put(LED_RED, 1);
        printf("LED vermelho ligado.\n");

        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
    }
    else if (command_ == 'g')
    {
        // Liga o LED verde e apaga os outros
        gpio_put(LED_GREEN, 1);
        printf("LED verde ligado.\n");

        gpio_put(LED_RED, 0);
        gpio_put(LED_BLUE, 0);
    }
    else if (command_ == 'b')
    {
        // Liga o LED azul e apaga os outros
        gpio_put(LED_BLUE, 1);
        printf("LED azul ligado.\n");

        gpio_put(LED_RED, 0);
        gpio_put(LED_GREEN, 0);
    }
    else if (command_ == '0')
    {
        // Apaga todos os LEDs
        printf("LEDS APAGADOS.\n");
        turn_off_leds();
    }
    else if (command_ == 's')
    {
        // Emite som no buzzer
        buzz_sound();
    }
    else
    {
        // Comando inválido
        printf("Comando desconhecido: %c\n", command_);
    }
}

int main()
{
    // Inicializar a comunicação serial e configurar GPIOs
    stdio_init_all(); // Inicializa a comunicação serial com baud rate 115200
    setup_gpio();     // Configura os GPIOs

    char command;

    while (1)
    {
        if (stdio_usb_connected())
        {
            // Lê um caractere da entrada serial
            command = getchar();      // Ler caractere
            process_command(command); // Processa o comando recebido
        }
    }

    return 0;
}
