/*
 * test_error_divide_by_zero.c
 *
 *  Created on: Jun 3, 2025
 *      Author: MaximilianLell
 */
#include "common_types.h"
#include "log.h"

/*=================================================================
 * Defines
 *=================================================================*/



/*=================================================================
 * Test implementations
 *=================================================================*/

// Example: Conversion of a raw value with calibration
static void test_sensor_divide_by_zero(void) {
    int raw_sensor_value = 0; // Sensor returns 0 (e.g., defective or not initialized)
    int calibration_factor = 100;
    // Conversion: physical value = calibration factor / sensor value
    volatile int physical_value = calibration_factor / raw_sensor_value; // Division by zero!

	log_info("physical calibrated value is %s", physical_value); 
}

void test_error_divide_by_zero(void) {
	test_sensor_divide_by_zero();
	log_info("passed");
}

