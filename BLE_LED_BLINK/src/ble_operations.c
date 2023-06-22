#include"headers.h"

/*
    This function configure the BLE 
*/

void ble_config()
{
    int err;
	bt_addr_le_t addr;

/*-----------If you want to change the default address-----------------------*/    
    // Change BLE Address
	err = bt_addr_le_from_str("FF:EE:DD:CC:BB:AA", "random", &addr);
	if(err) {
		printk("Invalid BT address");
	}

    // Change BLE Address
    err = bt_id_create(&addr, NULL);
    if (err < 0) {
        printk("Creating new ID failed (err %d)\n", err);
    }
/*------------------------------------------------------------------------*/
    
    // Enable the BLE
    err = bt_enable(NULL);
	if (err) {
		printf("Bluetooth init failed (err %d)\n", err);
		return;
	}

    // register service characteristics callbacks
    register_led_service_characteristics();

    // Advertise Service
    ble_advertise();

    // register callback
    register_callback();

}

