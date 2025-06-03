#ifndef ONBOARDTEST_TESTDECLERATIONS_H
#define ONBOARDTEST_TESTDECLERATIONS_H

/*=================================================================
 * enums for the test scenarios
 *=================================================================*/

typedef enum
{
    // Generic enums - do not modify
    E_TEST_NONE,

    // enums for the test scenarios
    E_TEST_BLINKY_LED,

	// enums for the error scenarios
	E_SIMULATE_ERROR_DIVIDE_BY_ZERO,

    // Generic enum - do not modify
    E_TEST_LAST
} OnBoardTest_Test_e;

/*=================================================================
 * typedefs for the test functions
  *=================================================================*/

typedef void (*OnBoardTest_fn_t)(void);

/*=================================================================
 * Test declarations
 *=================================================================*/

void test_blinky_led();
void test_error_divide_by_zero();

#endif // ONBOARDTEST_TESTDECLERATIONS_H
