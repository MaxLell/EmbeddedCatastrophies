/*
 * blinky_led.c
 *
 *  Created on: Jun 3, 2025
 *      Author: MaximilianLell
 */

#include "blinky_led.h"
#include "main.h"

void blinky_led_toggle(void) {
    HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

void blinky_led_enable(void) {
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
}

void blinky_led_disable(void) {
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
}


