/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "headers.h"
#include "zephyr/kernel.h"



void main(void)
{
	printk("Hello World! \r\n");
	gpio_configure();
	
	while(1)
	{
		toggle_both();
		k_msleep(LED_DELAY);
	}
}
