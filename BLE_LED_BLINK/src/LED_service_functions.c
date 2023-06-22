#include"headers.h"

/*
    Define the application callback function for controlling the LED from mobile
*/
static void app_led_cb(bool led_state)
{
	turn_ble_led_on_off((int)led_state);
}

/* Declare a varaible app_callbacks of type my_led_cb and initiate its members to the applications call back functions .*/
static struct my_led_cb app_callbacks = {
	.led_cb    = app_led_cb,
	// .button_cb = app_button_cb,
};

void register_led_service_characteristics()
{
	int err;
	err = my_led_service_init(&app_callbacks);
	if (err) {
		printk("Failed to init LED service (err:%d)\n", err);
		return;
	}
}