#ifndef GPIO_OPERATIONS_H
#define GPIO_OPERATIONS_H

/* LED Delay */
#define LED_DELAY   5000

//-----get the node reference----
#define BLUE_LED DT_ALIAS(blueled)
#define GREEN_LED DT_ALIAS(greenled)

//-----Built IN LED----------
#define built_in_LED1 DT_ALIAS(led0)
#define built_in_LED2 DT_ALIAS(led1)

//------BLE LED----------
#define BLE_LED DT_ALIAS(led3)

/*
    This function sets the initial values to the GPIO Pins
*/
void gpio_intial_values(void);

/*
    This function will set the GOPIO configurations
*/
void gpio_configure(void);

/*
    This function toggle both the LEDs
*/
void toggle_both(void);

/*
    Turn LED ON/OFF
*/
void turn_green_led_on_off(int);

/*
    Turn BLE LED ON/OFF
*/
void turn_ble_led_on_off(int);

#endif