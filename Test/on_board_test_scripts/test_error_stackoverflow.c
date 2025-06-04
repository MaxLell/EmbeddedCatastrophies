/*
 * test_error_stackoverflow.c
 *
 *  Created on: Jun 4, 2025
 *      Author: MaximilianLell
 */

/*=================================================================
 * Includes
 *=================================================================*/

#include "common_types.h"
#include "math.h"
#include "stdlib.h"
#include "log.h"
#include "custom_assert.h"

/*=================================================================
 * Defines
 *=================================================================*/

#define SIGNAL_LENGTH 1000
#define WINDOW_SIZE 3

/*=================================================================
 * static variables
 *=================================================================*/

static s32 g_signal[SIGNAL_LENGTH] = { 0 };

/*=================================================================
 * private function declerations
 *=================================================================*/

static void calculate_mean_over_window(s32 *input_signal, s32 *output_signal,
		s32 window_size, s32 signal_length);

static void create_random_noisy_signal(s32 *inout_signal, s32 length);

/*=================================================================
 * private function definitions
 *=================================================================*/

static void calculate_mean_over_window(s32 *input_signal, s32 *output_signal,
		s32 window_size, s32 signal_length)
{
	ASSERT(input_signal);
	ASSERT(output_signal);
	ASSERT(window_size < signal_length);
	ASSERT(window_size > 0);
	ASSERT(signal_length > 0);

	for (s32 i = 0; i < signal_length; i++)
	{
		s32 sum = 0;
		s32 count = 0;
		for (s32 j = 0; j <= window_size; j++)
		{
			s32 idx = i + j;
			if (idx >= 0 && idx < signal_length)
			{
				sum += input_signal[idx];
				count++;
			}
		}
		output_signal[i] = (count > 0) ? (sum / count) : 0;
	}
}

static void create_random_noisy_signal(s32 *inout_signal, s32 length)
{
	ASSERT(inout_signal);
	ASSERT(length > 0);
	for (s32 i = 0; i < length; i++)
	{
		inout_signal[i] = (s32) (100 * sin(2 * M_PI * i / 100.0) + 50
				+ (rand() % 10 - 5));
	}
}

/*=================================================================
 * Test implementations
 *=================================================================*/

void test_error_stack_overflow(void)
{
	s32 tmp_mean_signal[SIGNAL_LENGTH] = { 0 };
	create_random_noisy_signal(g_signal, SIGNAL_LENGTH);

	// Calculate the mean of the signal
	calculate_mean_over_window(g_signal,
							   tmp_mean_signal,
							   WINDOW_SIZE,
							   SIGNAL_LENGTH);

	log_info("passed");
	return;
}
