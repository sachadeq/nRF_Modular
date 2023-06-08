#ifndef GPIO_OPERATIONS_H
#define GPIO_OPERATIONS_H

/* LED Delay */
#define LED_DELAY   5000

//-----get the node reference----
#define BLUE_LED DT_ALIAS(blueled)
#define GREEN_LED DT_ALIAS(greenled)

/*
    This function will set the GOPIO configurations
*/
void gpio_configure(void);

/*
    This function toggle both the LEDs
*/
void toggle_both(void);

#endif