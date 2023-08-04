#ifndef SRC_GOPNIK_DEAD10C5_H_
#define SRC_GOPNIK_DEAD10C5_H_

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

  Date   : Aug 03, 2023
  Version: 0.2
  Copyright 2023 dead10c5
*/


#define VERSION "v0.2 - 03 Aug 2023 - гопник badge - Путин хуйло"

#include <Arduino.h>
#include <Wire.h>

// You can specify TX_PIN here (before the line #include "ATtinySerialOut.hpp")
// #define TX_PIN PB1
// #include "ATtinySerialOut.hpp"

#define MPU6050_ADDR 0x68

float AccX, AccY, AccZ, MAccX, MAccY, MAccZ;

volatile int mode = 0;

const byte LED_BOTTOM = 10; // PB0 on pin2
const byte LED_MIDDLE = 9;  // PB1 on pin3
const byte LED_TOP = 8;     // PB2 on pin5
const byte BUTTON = 0;      // PA0 - PCINT0

#endif  // SRC_GOPNIK_DEAD10C5_H_
