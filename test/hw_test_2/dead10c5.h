/*!
   @file dead10c5.h
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


  # SPDX-FileCopyrightText: 2023 DE:AD:10:C5 <thedevilsvoice@dead10c5.org>
  #
  # SPDX-License-Identifier: GPL-3.0-or-later

  Date   : May 15, 2023
  Version: 0.1
*/
#ifndef DEAD10C5_H
#define DEAD10C5

#define VERSION "v0.1 - 15 May 2023 - гопник badge - Путин хуйло"

#include <Arduino.h>
#include <Wire.h>

//#define TX_PIN PB1 // You can specify TX_PIN here (before the line #include "ATtinySerialOut.hpp")
//#include "ATtinySerialOut.hpp"

#define MPU6050_ADDR 0x68

const uint8_t BOTTOM_ROW = PB0;  // PB0 on pin2
const uint8_t MIDDLE_ROW = PB1; //PA1;  // PB1 on pin3
const uint8_t TOP_ROW = PB2;     // PB2 on pin5

// use this struct to get data back from MPU6050
struct offsets {
  float x;
  float y;
  float z;
};

#endif