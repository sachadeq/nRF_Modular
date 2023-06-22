# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(led_blink)

target_sources(app PRIVATE src/main.c src/gpio_operations.c 
                src/ble_operations.c
                src/ble_advertise.c
                src/ble_service.c
                src/LED_service_functions.c)
