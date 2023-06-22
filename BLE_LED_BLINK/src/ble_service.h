#ifndef BLE_SERVICE_H
#define BLE_SERVICE_H

// Define BLE Service (Demo Service)
#define BT_UUID_DS_VAL BT_UUID_128_ENCODE(0x00001528, 0x1212, 0xefde, 0x1523, 0x785feabcd123)

// LED Characteristic UUID
#define BT_UUID_LED_VAL BT_UUID_128_ENCODE(0x00001529, 0x1212, 0xefde, 0x1523, 0x785feabcd123)

#define BT_UUID_DS BT_UUID_DECLARE_128(BT_UUID_DS_VAL)
#define BT_UUID_LED BT_UUID_DECLARE_128(BT_UUID_LED_VAL)


/*----Call back functions for connection and disconnection------*/
void on_connected(struct bt_conn *conn, uint8_t err);
void on_disconnected(struct bt_conn *conn, uint8_t reason);


/****Register Callback*****/
void register_callback(void);

/*------for LED Characteristic----------*/
/** @brief Callback type for when an LED state change is received. */
typedef void (*led_cb_t)(const bool led_state);

/** @brief Callback struct used by the Service. */
struct my_led_cb {
	/** LED state change callback. */
	led_cb_t    led_cb;
	// /** Button read callback. */
	// button_cb_t button_cb;
};

/** @brief Initialize the LBS Service.
 *
 * This function registers application callback functions with the My LBS
 * Service 
 *
 * @param[in] callbacks Struct containing pointers to callback functions
 *			used by the service. This pointer can be NULL
 *			if no callback functions are defined.
 *
 *
 * @retval 0 If the operation was successful.
 *           Otherwise, a (negative) error code is returned.
 */
int my_led_service_init(struct my_led_cb *callbacks);



#endif