#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

volatile int estado = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna entre os estados do semáforo
    if (estado == 0) {
        gpio_put(LED_RED, 0);
        gpio_put(LED_YELLOW, 1);
        estado = 1;
    } else if (estado == 1) {
        gpio_put(LED_YELLOW, 0);
        gpio_put(LED_GREEN, 1);
        estado = 2;
    } else {
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_RED, 1);
        estado = 0;
    }
    return true; // Mantém o timer ativo
}

int main() {
    stdio_init_all();
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    // Inicializa com o LED vermelho ligado
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while (true) {
        printf("Semáforo operando...");
        sleep_ms(1000); // Mensagem a cada segundo
    }
}
