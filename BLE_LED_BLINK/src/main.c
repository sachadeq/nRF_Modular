/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "headers.h"


void main(void)
{
	printk("Hello BLE-LED! \r\n");
	gpio_configure();
	ble_config();
	
	while(1)
	{
		// toggle_both();
		// k_msleep(LED_DELAY);
		k_msleep(IDLE_DELAY);
	}
	
}
