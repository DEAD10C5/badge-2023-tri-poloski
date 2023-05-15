/*!
   @file hardware_test.ino
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


  # SPDX-FileCopyrightText: 2023 DE:AD:10:C5 <polr@dead10c5.org>
  #
  # SPDX-License-Identifier: GPL-3.0-or-later

   Date   : May 14, 2023
   Version: 0.1
*/

#include <Arduino.h>
#include <TinyMPU6050.h>

MPU6050 mpu(Wire);

void setup()
{
  pinMode(PA0, OUTPUT);
  pinMode(PA1, OUTPUT);
  pinMode(PB2, OUTPUT);
  flash_up();
  mpu.Initialize();
  // mpu.Calibrate();
  flash_down();
}

void lights(int x, int y, int z)
{
  digitalWrite(PA0, x);
  digitalWrite(PA1, y);
  digitalWrite(PB2, z);
}

void flash_up()
{

  lights(1, 0, 0);
  delay(100);
  lights(1, 1, 0);
  delay(100);
  lights(1, 1, 1);
  delay(100);
  lights(0, 0, 0);
}

void flash_down()
{
  lights(0, 0, 1);
  delay(100);
  lights(0, 1, 1);
  delay(100);
  lights(1, 1, 1);
  delay(100);
  lights(0, 0, 0);
}

void loop()
{
  mpu.Execute();
  float acc = mpu.GetRawAccY();

  if (acc < 1.0)
  {
    lights(1, 0, 0);
  }
  else if (1.0 < acc < 1.0001)
  {
    lights(1, 1, 0);
  }
  else if (1.0001 < acc)
  {
    lights(1, 1, 1);
  }
  else
  {
    lights(0, 0, 0);
  }

  delay(100);
}
