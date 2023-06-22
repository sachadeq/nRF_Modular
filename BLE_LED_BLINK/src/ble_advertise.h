#ifndef BLE_ADVERTISE_H
#define BLE_ADVERTISE_H

#define DEVICE_NAME             CONFIG_BT_DEVICE_NAME
#define DEVICE_NAME_LEN         (sizeof(DEVICE_NAME) - 1)

// advertise service 
void ble_advertise(void);

#endif