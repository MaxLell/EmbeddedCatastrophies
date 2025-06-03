/*
 * test_error_divide_by_zero.c
 *
 *  Created on: Jun 3, 2025
 *      Author: MaximilianLell
 */


/*=================================================================
 * Mocked functions
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

void test_error_divide_by_zero(void) {
	test_divide_by_zero_crashes_into_hardfault();
}

