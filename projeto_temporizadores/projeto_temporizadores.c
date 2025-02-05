#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <stdlib.h>
#include "pico/stdlib.h"

#define led_pin_red  11
#define led_pin_yellow  12
#define led_pin_green  13

bool led_state = false;
int contador = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    contador++;
    if (contador == 1) {
        gpio_put(led_pin_red, !led_state);
        gpio_put(led_pin_yellow, led_state);
        gpio_put(led_pin_green, led_state);
    }
    if (contador == 2) {
        gpio_put(led_pin_yellow, !led_state);
        gpio_put(led_pin_red, led_state);
        gpio_put(led_pin_green, led_state);
    }
    if (contador == 3) {
        gpio_put(led_pin_green, !led_state);
        gpio_put(led_pin_red, led_state);
        gpio_put(led_pin_yellow, led_state);
        contador = 0;
    }
    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}

int main()
{
    stdio_init_all();

    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);

    gpio_init(led_pin_yellow);
    gpio_set_dir(led_pin_yellow, GPIO_OUT);

    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);

    //Declaração de uma estrutura de temporizador repetitivo
    struct repeating_timer timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        // Pausa de 10 segundos para reduzir o uso da CPU.
        printf("Rotina while\n");
        sleep_ms(10000);
    }
}
