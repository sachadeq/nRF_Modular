# BLE-LEDs Blink 
This program does the following:
1. Bradcast with custom address
2. Has connection callback
    1. LED gets turned ON when connected
    2. LED gets turned OFF when disconnected
3. 
## With Arduino nano 33 BLE
### Arduino PIN Connections
    D2 (P1.11) --> Blue LED
    D3 (P1.12) --> Red LED

### Program Flashing Issues
1. nRF connect on VS Code was not detecting the board and hence couldn't flash the device (Arduino nano 33 BLE).

## With nRF52840DK
We created a different build configuration file in the same project
### Pin connections
    P0.04 --> Blue LED
    P0.28 --> Red LED

