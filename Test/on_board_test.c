#include "on_board_test.h"
#include "custom_assert.h"
#include "on_board_test_declerations.h"
#include <stdbool.h>

/*=================================================================
 * Global variables
 *=================================================================*/

//! variable that holds the id of the test, which is currently running
OnBoardTest_Test_e g_nof_current_test = E_SIMULATE_ERROR_DIVIDE_BY_ZERO;

/**
 * loop Function Array
 */
static const OnBoardTest_fn_t test_lookup_table[E_TEST_LAST] = {
    [E_TEST_BLINKY_LED] = test_blinky_led,
	[E_SIMULATE_ERROR_DIVIDE_BY_ZERO] = test_error_divide_by_zero,
};

bool on_board_test_is_testing_enabled(void)
{
    ASSERT(g_nof_current_test < E_TEST_LAST);

    return g_nof_current_test != E_TEST_NONE;
}

void on_board_test_run(void)
{
    ASSERT(g_nof_current_test != E_TEST_NONE);
    ASSERT(g_nof_current_test < E_TEST_LAST);

    // run the respective test
    test_lookup_table[g_nof_current_test]();
}
