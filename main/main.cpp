/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

// #include <stdio.h>
// #include <inttypes.h>
// #include "sdkconfig.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "esp_chip_info.h"
// #include "esp_flash.h"
// #include "esp_system.h"

#include <iostream>
#include <dac7718.hpp>
// #include <esp_mac.h>

extern "C" void app_main()
{
    
    DAC7718::ConfigPacket config_packet{ true };
    auto [packet_bytes, packet_bits] = config_packet.serialize();
    for (auto byte : packet_bytes)
        std::cout << std::hex << unsigned(byte);
    
    std::cout << std::endl << "Done";

}
