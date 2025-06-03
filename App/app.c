/*
 * app.c
 *
 *  Created on: Jun 2, 2025
 *      Author: maxkoell
 */
#include "on_board_test.h"
#include "log.h"

void app_main(void){
	bool testing_is_enabled = on_board_test_is_testing_enabled();
	if (testing_is_enabled) {
		log_info("Running Test");
		on_board_test_run();
	} else {
		for(;;) {}
	}
}
