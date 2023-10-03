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

  Date   : Aug 04, 2023
  Version: 0.2
*/
#ifndef DEAD10C5_H
#define DEAD10C5

#define VERSION "v0.2 - 04 Aug 2023 - гопник badge - Путин хуйло"

#include <Arduino.h>
#include <Wire.h>

// #define TX_PIN PB1 // You can specify TX_PIN here (before the line #include "ATtinySerialOut.hpp")
// #include "ATtinySerialOut.hpp"

#define MPU6050_ADDR 0x68

float AccelX, AccelY, AccelZ, Temp, GyroX, GyroY, GyroZ;

const byte LED_BOTTOM = 10; // PB0 on pin2
const byte LED_MIDDLE = 9;  // PB1 on pin3
const byte LED_TOP = 8;     // PB2 on pin5
const byte BUTTON = 0;      // PA0 - PCINT0

volatile int mode = 0;

void read_mpu();
void blink(int, int);
void lights(int);

#endif