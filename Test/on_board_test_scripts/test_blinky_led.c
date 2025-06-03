#include "blinky_led.h"
#include "delay.h"
#include "main.h"


/*=================================================================
 * Mocked functions
 *=================================================================*/

/*=================================================================
 * Test implementations
 *=================================================================*/

void test_led_can_be_enabled(void)
{
    blinky_led_enable();
    delay_ms(500);
}

void test_led_can_be_disabled(void)
{
    blinky_led_disable();
    delay_ms(500);
}

void test_led_can_be_toggled(void)
{
    blinky_led_enable();
    delay_ms(100); // Wait for a short period to observe the LED state
    blinky_led_toggle();
    delay_ms(100); // Wait again to observe the toggled state
    blinky_led_disable();
}

/*=================================================================
 * Test Runner
 *=================================================================*/

void test_blinky_led(void)
{
    // Run the tests
    test_led_can_be_enabled();
    test_led_can_be_disabled();
    test_led_can_be_toggled();
}