#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define led_blue 11
#define led_red 12
#define led_green 13
const uint but_A = 5;

bool led_on = false;        // Variável global para armazenar o estado do LED (não utilizada neste código).
bool leds_active = false;    // Indica se o LED está atualmente aceso (para evitar múltiplas ativações).
absolute_time_t turn_off_time;  // Variável para armazenar o tempo em que o LED deve ser desligado (não utilizada neste código).


int64_t turn_off_red(alarm_id_t id, void *user_data);
int64_t turn_off_green(alarm_id_t id, void *user_data);

// Função de callback para desligar o LED após o tempo programado.
int64_t turn_off_blue(alarm_id_t id, void *user_data) {
    gpio_put(led_blue, false);
    add_alarm_in_ms(3000, turn_off_red, NULL, false);  
    return 0;
}

int64_t turn_off_red(alarm_id_t id, void *user_data) {
    gpio_put(led_red, false);
    add_alarm_in_ms(3000, turn_off_green, NULL, false);  
    return 0;
}

int64_t turn_off_green(alarm_id_t id, void *user_data) {
    gpio_put(led_green, false);
    leds_active = false;
    return 0;
}
int main()
{
    stdio_init_all();

    gpio_init(led_blue);
    gpio_set_dir(led_blue, GPIO_OUT);

    gpio_init(led_red);
    gpio_set_dir(led_red, GPIO_OUT);

    gpio_init(led_green);
    gpio_set_dir(led_green, GPIO_OUT);

    gpio_init(but_A);
    gpio_set_dir(but_A, GPIO_IN);
    gpio_pull_up(but_A);



    while (true) {
        // Verifica se o botão foi pressionado (nível baixo no pino) e se o LED não está ativo.
        if (gpio_get(but_A) == 0 && !leds_active) {
            // Adiciona um pequeno atraso para debounce, evitando leituras errôneas.
            sleep_ms(50);

            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(but_A) == 0) {
                // Liga o LED configurando o pino LED_PIN para nível alto.
                gpio_put(led_blue, true);
                gpio_put(led_red, true);
                gpio_put(led_green, true);

                // Define 'led_active' como true para indicar que o LED está aceso.
                leds_active = true;

                add_alarm_in_ms(3000, turn_off_blue, NULL, false);
        
            }
        // Introduz uma pequena pausa de 10 ms para reduzir o uso da CPU.
        // Isso evita que o loop seja executado muito rapidamente e consuma recursos desnecessários.
        
        }
        sleep_ms(10);
    }
    
    return 0;
}