/*
 * delay.c
 *
 *  Created on: Jun 3, 2025
 *      Author: MaximilianLell
 */

#include "delay.h"
#include "cmsis_os.h"

void delay_ms(uint32_t ms) {
    osDelay(ms);
}
