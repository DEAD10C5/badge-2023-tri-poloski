/*!
   @file hardware_test.ino
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


  # SPDX-FileCopyrightText: 2023 DE:AD:10:C5 <thedevilsvoice@dead10c5.org>
  #
  # SPDX-License-Identifier: GPL-3.0-or-later
  Date   : May 13, 2023
  Version: 0.3
*/

#include "dead10c5.h"

void setup() {
  Serial.println(F("Using library version "));
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  pinMode(BOTTOM_ROW, OUTPUT);
  pinMode(MIDDLE_ROW, OUTPUT);
  pinMode(TOP_ROW, OUTPUT);
}

void loop() {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDR, 14);

  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();

  gx = Wire.read() << 8 | Wire.read();
  gy = Wire.read() << 8 | Wire.read();
  gz = Wire.read() << 8 | Wire.read();

  lights(0); 

  Serial.print("Accelerometer: ");
  Serial.print(ax);
  Serial.print(", ");
  Serial.print(ay);
  Serial.print(", ");
  Serial.println(az);

  Serial.print("Gyroscope: ");
  Serial.print(gx);
  Serial.print(", ");
  Serial.print(gy);
  Serial.print(", ");
  Serial.println(gz);

  delay(1000);

  lights(1);
}

void lights(int x) {
  digitalWrite(BOTTOM_ROW, x);
  digitalWrite(MIDDLE_ROW, x);
  digitalWrite(TOP_ROW, x);
  delay(100);
}
