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
    // Gera um som por 500 ms
    printf("Emitindo som no buzzer.\n");
    for (int i = 0; i < 500; i++)
    {
        gpio_put(BUZZER, 1);
        sleep_us(1000); // 1 ms ligado
        gpio_put(BUZZER, 0);
        sleep_us(1000); // 1 ms desligado
    }
}

// Função para processar comandos
void process_command(char command_)
{
    if (command_ == 'r')
    {
        gpio_put(LED_RED, 1);
        printf("LED vermelho ligado.\n");

        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
    }
    else if (command_ == 'g')
    {
        gpio_put(LED_GREEN, 1);
        printf("LED verde ligado.\n");

        gpio_put(LED_RED, 0);
        gpio_put(LED_BLUE, 0);
    }
    else if (command_ == 'b')
    {
        gpio_put(LED_BLUE, 1);
        printf("LED azul ligado.\n");

        gpio_put(LED_RED, 0);
        gpio_put(LED_GREEN, 0);
    }
    else if (command_ == '0')
    {
        printf("LEDS APAGADOS.\n");
        turn_off_leds();
    }
    else if (command_ == 's')
    {
        buzz_sound(); // Emite som no buzzer
    }
    else
    {
        printf("Comando desconhecido: %c\n", command_);
    }
}

int main()
{
    // Inicializar a comunicação serial e configurar GPIOs
    stdio_init_all(); // Inicializa a comunicação serial com baud rate 115200
    setup_gpio();

    char command;

    while (1)
    {
        if (stdio_usb_connected())
        {
            command = getchar();      // Ler caractere
            process_command(command); // Função que processa comando
        }
    }

    return 0;
}
