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
  Serial.begin(15200);
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);           // Talk to the register 6B
  Wire.write(0x00);           // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true); // end the transmission

  pinMode(LED_BOTTOM, OUTPUT);
  pinMode(LED_MIDDLE, OUTPUT);
  pinMode(LED_TOP, OUTPUT);
}

void loop()
{
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true);
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value

  Serial.print("ay: ");
  Serial.println(AccY * 1000);

  blink(LED_BOTTOM, 5);
  
  if (AccY < 0)
  {
    blink(LED_BOTTOM, 5);
  }
  else if (AccY > 0)
  {
    blink(LED_TOP, 5);
  }
  else
  {
    blink(LED_MIDDLE, 5); // this means zero, or some crazy undefined value
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

void lights(int x)
{
  digitalWrite(LED_BOTTOM, x);
  digitalWrite(LED_MIDDLE, x);
  digitalWrite(LED_TOP, x);
  delay(50);
}

/* watching this interrupt to change mode if they are
moving the badge around the space time contiuum */
// ISR(PCINT0_vect)
// {
//   if (digitalRead(BUTTON) == LOW)
//   {
//     Serial.print("franklin ay: ");
//     Serial.println(AccY * 1000);
//   }
// }