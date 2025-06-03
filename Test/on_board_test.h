#ifndef ONBOARDTEST_H
#define ONBOARDTEST_H

/*=================================================================
 * Include
 *=================================================================*/

#include "on_board_test_declerations.h"
#include <stdbool.h>

/*=================================================================
 * Dekleration
 *=================================================================*/

bool on_board_test_is_testing_enabled(void);

void on_board_test_run(void);

#endif // ONBOARDTEST_H
