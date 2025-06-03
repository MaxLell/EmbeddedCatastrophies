/*
 * test_error_divide_by_zero.c
 *
 *  Created on: Jun 3, 2025
 *      Author: MaximilianLell
 */
#include "common_types.h"
#include "math.h"
#include <stdlib.h>
#include "log.h"

/*=================================================================
 * define
 *=================================================================*/

/*=================================================================
 * Test implementations
 *=================================================================*/

void test_divide_by_zero_crashes_into_hardfault(void)
{
	int a = 10;
	int b = 0;
	volatile int c = a / b;
}

void calculate_mean_over_window(s32 *input_signal,  s32 *output_signal, s32 window_size, s32 signal_length) {
	// Calculate the mean of the input signal over a sliding window
	for (s32 i = 0; i < signal_length; i++) {
		s32 sum = 0;
		s32 count = 0;
		for (s32 j = 0; j <= window_size; j++) {
			s32 index = i + j;
			if (index >= 0 && index < signal_length) {
				sum += input_signal[index];
				count++;
			}
		}
//		output_signal[i] = count > 0 ? sum / count : 0; // Avoid division by zero
		output_signal[i] = sum / count;
	}
}
#define SIGNAL_LENGTH 1000

void test_divide_by_zero_complex(void) {
	s32 mean_signal[SIGNAL_LENGTH] = {0};
	static s32 signal[SIGNAL_LENGTH] = {0};
	// Create a long signal which has the shape of roughly a sine wave also add in a slight offset and a bit of noise

	for (s32 i = 0; i < SIGNAL_LENGTH; i++) {
		 s32 tmp_value = (s32)(100 * sin(2 * M_PI * i / 100.0) + 50 + (rand() % 10 - 5)); 
		 if (tmp_value == 0) {
			signal[i] = tmp_value;
			i++;
			signal[i] = tmp_value;
			i++;
			signal[i] = tmp_value;
		 }
		 signal[i] = tmp_value;
	}

	s32 window_size = 3; // Size of the window for calculating the mean
	// Calculate the mean of the signal
	calculate_mean_over_window(signal, mean_signal, window_size, SIGNAL_LENGTH);

	// Calculate the mean of th signal
	log_info("Huhu");
	return;
}

void test_error_divide_by_zero(void) {
	//test_divide_by_zero_crashes_into_hardfault();
	test_divide_by_zero_complex();
}

