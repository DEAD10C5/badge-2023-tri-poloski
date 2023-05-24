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

void setup()
{
  Serial.begin(9600);

  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); //We want to write to the PWR_MGMT_1 register (6B hex).
  // Wire.write(0x00); //enable temp sensor
  Wire.endTransmission();

  pinMode(BOTTOM_ROW, OUTPUT);
  pinMode(MIDDLE_ROW, OUTPUT);
  pinMode(TOP_ROW, OUTPUT);
}

void loop()
{
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDR, 14);

  int16_t gx, gy, gz;
  gx = Wire.read() << 8 | Wire.read();
  gy = Wire.read() << 8 | Wire.read();
  gz = Wire.read() << 8 | Wire.read();
  
  int16_t ax, ay, az;
  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();

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

  Serial.print("ay: ");
  Serial.println(ay);

  if (ay < 0)
  {
    blink(BOTTOM_ROW, 5);
  }
  else if (ay > 0)
  {
    blink(TOP_ROW, 5);
  }
  else
  {
    blink(MIDDLE_ROW, 5); // this means zero, or some crazy undefined value
  }
}

void blink(int row, int count)
{
  for (int x = 0; x <= count; x++)
  {
    digitalWrite(row, 1);
    delay(75);
    digitalWrite(row, 0);
    delay(75);
  }
}

/*
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
  delay(200);
  lights(1);
} */

void lights(int x)
{
  digitalWrite(BOTTOM_ROW, x);
  digitalWrite(MIDDLE_ROW, x);
  digitalWrite(TOP_ROW, x);
  delay(50);
}
