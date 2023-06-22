#include"headers.h"


//------get the pointer to the LEDs-----------
static const struct gpio_dt_spec blueLED = GPIO_DT_SPEC_GET(BLUE_LED, gpios);
static const struct gpio_dt_spec greenLED = GPIO_DT_SPEC_GET(GREEN_LED, gpios);

//---------For built-in LEDs---------
static const struct gpio_dt_spec builtInLED1 = GPIO_DT_SPEC_GET(built_in_LED1, gpios);
static const struct gpio_dt_spec builtInLED2 = GPIO_DT_SPEC_GET(built_in_LED2, gpios);

//---------For BLE LED---------------
static const struct gpio_dt_spec bleLED = GPIO_DT_SPEC_GET(BLE_LED, gpios);

void gpio_intial_values()
{
    gpio_pin_set_dt(&blueLED, 0);
    gpio_pin_set_dt(&greenLED, 0);
    gpio_pin_set_dt(&builtInLED1, 0);
    gpio_pin_set_dt(&builtInLED2, 0);
    gpio_pin_set_dt(&bleLED, 0);
}

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

    //----for built-in LEDs-------
    // Wait for the device to be ready
    if (!device_is_ready(builtInLED1.port)) {
		return;
	}
    if (!device_is_ready(builtInLED2.port)) {
		return;
	}

	// Set the direction of GPIOs
	gpio_pin_configure_dt(&blueLED, GPIO_OUTPUT);
    gpio_pin_configure_dt(&greenLED, GPIO_OUTPUT);

    gpio_pin_configure_dt(&builtInLED1, GPIO_OUTPUT);
    gpio_pin_configure_dt(&builtInLED2, GPIO_OUTPUT);

    gpio_pin_configure_dt(&bleLED, GPIO_OUTPUT);

    // Give initial values on LEDs
    gpio_intial_values();
}

/*
    toggle both LEDs
*/
void toggle_both()
{
    gpio_pin_toggle_dt(&blueLED);
    gpio_pin_toggle_dt(&greenLED);
}

/*
    Turn LED ON/OFF
*/
void turn_green_led_on_off(int val)
{
    printf("Writing %d to green LED\n", val);
    gpio_pin_set_dt(&greenLED, val);

    gpio_pin_set_dt(&builtInLED1, val);
}

void turn_ble_led_on_off(int val)
{
    gpio_pin_set_dt(&bleLED, val);
}