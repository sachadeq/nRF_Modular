/*
    This file contain functions related to callback and services
*/
#include"headers.h"


struct bt_conn *my_conn = NULL;

// Conncetion callback to indicate connected and disconnected state
struct bt_conn_cb connection_callbacks = {
    .connected              = on_connected,
    .disconnected           = on_disconnected,
};

/*------on_connected Call Back--------*/
void on_connected(struct bt_conn *conn, uint8_t err)
{
    if (err) {
        printf("Connection error %d\n", err);
        return;
    }
    printf("Connected\n");
    my_conn = bt_conn_ref(conn);

    /* Turn ON Green LED */
    turn_green_led_on_off(1);
}

/*------on_disconnected Call Back--------*/
void on_disconnected(struct bt_conn *conn, uint8_t reason)
{
    printf("Disconnected. Reason %d\n", reason);
    bt_conn_unref(my_conn);

    /* Turn OFF Green LED */
    turn_green_led_on_off(0);
}

/*-------LED Characteristic Callback-----------*/
static struct my_led_cb       led_cb;
static ssize_t write_led_callback(struct bt_conn *conn,
			 const struct bt_gatt_attr *attr,
			 const void *buf,
			 uint16_t len, uint16_t offset, uint8_t flags)
{
	// LOG_DBG("Attribute write, handle: %u, conn: %p", attr->handle,
	// 	(void *)conn);
	if (len != 1U) {
		// LOG_DBG("Write led: Incorrect data length");
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
	}
	if (offset != 0) {
		// LOG_DBG("Write led: Incorrect data offset");
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_OFFSET);
	}
	if (led_cb.led_cb) {
		//Read the received value 
		uint8_t val = *((uint8_t *)buf);
		if (val == 0x00 || val == 0x01) {
			//Call the application callback function to update the LED state
			led_cb.led_cb(val ? true : false);
		} else {
			// LOG_DBG("Write led: Incorrect value");
			return BT_GATT_ERR(BT_ATT_ERR_VALUE_NOT_ALLOWED);
		}
	}
	return len;
}

/********Register callback*************/
void register_callback()
{
    // Registering Callbacks
    bt_conn_cb_register(&connection_callbacks);
}

/* A function to register application callbacks for the LED characteristics  */
int my_led_service_init(struct my_led_cb *callbacks)
{
	if (callbacks) {
		led_cb.led_cb    = callbacks->led_cb;
		// lbs_cb.button_cb = callbacks->button_cb;
	}

	return 0;
}

/*-----LED Service Characteristic declaration---------*/
BT_GATT_SERVICE_DEFINE(sachin_demo_led, BT_GATT_PRIMARY_SERVICE(BT_UUID_DS), 
                        BT_GATT_CHARACTERISTIC(BT_UUID_LED, 
                                                BT_GATT_CHRC_WRITE,
                                                BT_GATT_PERM_WRITE,
                                                NULL, write_led_callback, NULL));

