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
  //Serial1.begin(9600); // could probably bump this speed high, not sure why though
  mpu.Initialize();
  mpu.Calibrate();
  /*
  Serial1.print(F("взаимоблокировщики Русский хардбасс: "));
  Serial1.println(VERSION);
  Serial1.println(F("Concept: Yaya Pancho"));
  Serial1.println(F("Translations: @muscovitebob"));
  Serial1.println(F("Artwork: @p0lr_"));
  Serial1.println(F("Hardware/software: @p0lr_ @thedevilsvoice"));
  delay(1000);
  */

  pinMode(BOTTOM_ROW, OUTPUT);
  pinMode(MIDDLE_ROW, OUTPUT);
  pinMode(TOP_ROW, OUTPUT);
}

void loop()
{
  mpu.Execute();
  struct offsets myOffsets;

  myOffsets = getOffsets();

  lights(0);
  lights(1);
}

void lights(int x)
{
  digitalWrite(BOTTOM_ROW, x);
  digitalWrite(MIDDLE_ROW, x);
  digitalWrite(TOP_ROW, x);
  delay(100);
}

struct offsets getOffsets()
{
  struct offsets myOffsets;

  myOffsets.x = mpu.GetGyroXOffset();
  myOffsets.y = mpu.GetGyroYOffset();
  myOffsets.z = mpu.GetGyroZOffset();

  return myOffsets;
}