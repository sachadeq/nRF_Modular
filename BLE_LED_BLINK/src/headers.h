#include <stdio.h>
#include <zephyr/kernel.h>
// #include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/addr.h>

#include <zephyr/bluetooth/gatt.h>

/*---My Custom Functions----*/
#include "gpio_operations.h"
#include "ble_operations.h"
#include "ble_advertise.h"
#include "ble_service.h"
#include "LED_service_functions.h"

/***********/
#define IDLE_DELAY 100 // milliseconds