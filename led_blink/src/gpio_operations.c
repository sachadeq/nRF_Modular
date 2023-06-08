#include"headers.h"


//------get the pointer to the LEDs-----------
static const struct gpio_dt_spec blueLED = GPIO_DT_SPEC_GET(BLUE_LED, gpios);
static const struct gpio_dt_spec greenLED = GPIO_DT_SPEC_GET(GREEN_LED, gpios);

void gpio_configure()
{
    printf("Inside GPIO Configurations\r\n");

    // Wait for the device to be ready
    if (!device_is_ready(blueLED.port)) {
		return;
	}
    if (!device_is_ready(greenLED.port)) {
		return;
	}

	// Set the direction of GPIOs
	gpio_pin_configure_dt(&blueLED, GPIO_OUTPUT);
    gpio_pin_configure_dt(&greenLED, GPIO_OUTPUT);
}

/*
    toggle both LEDs
*/

void toggle_both()
{
    gpio_pin_toggle_dt(&blueLED);
    gpio_pin_toggle_dt(&greenLED);
}