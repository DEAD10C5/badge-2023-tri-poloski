/*!
   @file i2c_scan.ino
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


  # SPDX-FileCopyrightText: 2023 DE:AD:10:C5 <thedevilsvoice@dead10c5.org>
  #
  # SPDX-License-Identifier: GPL-3.0-or-later

  Date   : May 17, 2023
  Version: 0.1
*/
#include "dead10c5.h"

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // Print the current time to the serial monitor.
  Serial.print(millis());
  Serial.println(" ms");

  // Scan the I2C bus for devices.
  byte count = 0;
  for (byte i = 1; i < 127; i++) {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found address: ");
      Serial.print(i);
      Serial.println();
      count++;
    }
  }

  // Print the number of devices found on the I2C bus.
  Serial.print("Found ");
  Serial.print(count);
  Serial.println(" devices.");

  delay(200);
}