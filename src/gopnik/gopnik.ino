/*!
   @file gopnik.ino
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/

  # SPDX-FileCopyrightText: 2023 DE:AD:10:C5 <polr@dead10c5.org>
  #
  # SPDX-License-Identifier: GPL-3.0-or-later
  Date   : August 02, 2023
  Version: 0.2

*/

#include "dead10c5.h"

void setup()
{
  Wire.begin();
  // Wire.setClock(400000L); //increase I2C speed to 400 khz 
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);           // Talk to the register 6B
  Wire.write(0);              // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true); // end the transmission
  // Wire.beginTransmission(MPU6050_ADDR);
  // Wire.write(0x19);           // SMPLRT register
  // Wire.write(0);              // 1khz data rate
  // Wire.endTransmission(true); // end the transmission

  // LED Pins
  pinMode(LED_BOTTOM, OUTPUT);
  pinMode(LED_MIDDLE, OUTPUT);
  pinMode(LED_TOP, OUTPUT);

  // Button Pin
  pinMode(BUTTON, INPUT);

  // Set up the interrupt
  cli();
  PCMSK0 |= (1 << PCINT0);
  GIMSK |= (1 << PCIE0);
  sei();

  // Flash the lights so we know setup is done
  lights(1, 1, 1);
  delay(3);
  lights(0, 0, 0);
}

void accelerometer()
{
  int del = 20;
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3D); //changed to 3D to read y --> old // Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true); //was 6
  // Wire.read()<<8|Wire.read(); //read X into _
  // AccelX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  // AccelX = Wire.read() << 8 | Wire.read();
  // AccelY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  // AccelY = Wire.read() << 8 | Wire.read();
  accelYraw = Wire.read()<<8|Wire.read();
  __INT16_TYPE__ secondYraw = Wire.read()<<8|Wire.read();
  __INT16_TYPE__ dif = accelYraw - secondYraw;

  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3D); //changed to 3D to read y --> old // Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 2, true); //was 6
  // Wire.read()<<8|Wire.read(); //read X into _
  // AccelX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  // AccelX = Wire.read() << 8 | Wire.read();
  // AccelY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  // AccelY = Wire.read() << 8 | Wire.read();
  accelYraw = Wire.read()<<8|Wire.read();
  // AccelY = (float) accelYraw / 16384.0;
  // Wire.read()<<8|Wire.read();
  // Wire.read()<<8|Wire.read();
  // Wire.read()<<8|Wire.read();
  // Wire.read()<<8|Wire.read();
  // Wire.read()<<8|Wire.read(); //read the rest into _ to see if this flushes the buffer since its 14 wide
  if (accelYraw && 1){
    bot = true;
    mid = false;
    top = false;
  } else if (accelYraw && 3){
    bot = false;
    mid = false;
    top = true;
  } else {
    bot = false;
    mid = true;
    top = false;
  }
  lights(bot,mid,top);
  // delay(del);
  // AccelZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value
  // AccelZ = Wire.read() << 8 | Wire.read();

  // Temp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)

  //GyroX = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  //GyroY = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  //GyroZ = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  // Serial.print(Tmp/340.00+36.53);  //equation for temperature in degrees C from datasheet
}

void lights(bool b, bool m, bool t)
{
  digitalWrite(LED_BOTTOM, b);
  digitalWrite(LED_MIDDLE, m);
  digitalWrite(LED_TOP, t);
}

/* watching this interrupt to change mode if they are
moving the badge around the space time contiuum */
ISR(PCINT0_vect)
{
  if (digitalRead(BUTTON) == LOW)
  {
    set_mode();
  }
}

void set_mode()
{
  mode = mode + 1;
  if (mode > 5)
  {
    mode = 0;
  }
}

void rollup()
{
  int del = 20;
  lights(1, 0, 0);
  delay(del);
  lights(0, 1, 0);
  delay(del);
  lights(0, 0, 1);
  delay(del);
  lights(0, 0, 0);
}

void rolldown()
{
  int del = 20;
  lights(0, 0, 1);
  delay(del);
  lights(0, 1, 0);
  delay(del);
  lights(1, 0, 0);
  delay(del);
  lights(0, 0, 0);
}

void flash()
{
  int del = 10;
  lights(1, 1, 1);
  delay(del);
  lights(0, 0, 0);
  delay(del);
}

void flashyrollup()
{
  int del = 10;
  for (int counter = 0; counter < 4; counter++)
  {
    lights(1, 0, 0);
    delay(del);
    lights(0, 0, 0);
    delay(del);
  }
  for (int counter = 0; counter < 4; counter++)
  {
    lights(0, 1, 0);
    delay(del);
    lights(0, 0, 0);
    delay(del);
  }
  for (int counter = 0; counter < 4; counter++)
  {
    lights(0, 0, 1);
    delay(del);
    lights(0, 0, 0);
    delay(del);
  }
}

void flashyrolldown()
{
  int del = 10;
  for (int counter = 0; counter < 4; counter++)
  {
    lights(0, 0, 1);
    delay(del);
    lights(0, 0, 0);
    delay(del);
  }
  for (int counter = 0; counter < 4; counter++)
  {
    lights(0, 1, 0);
    delay(del);
    lights(0, 0, 0);
    delay(del);
  }
  for (int counter = 0; counter < 4; counter++)
  {
    lights(1, 0, 0);
    delay(del);
    lights(0, 0, 0);
    delay(del);
  }
}

void alternate()
{
  int del = 30;
  lights(1, 0, 1);
  delay(del);
  lights(0, 1, 0);
  delay(del);
}

void loop()
{

  // this is the default mode
  if (mode == 0)
  {
    rollup();
  }
  else if (mode == 1)
  {
    rolldown();
  }
  else if (mode == 2)
  {
    flash();
  }
  else if (mode == 3)
  {
    flashyrollup();
  }
  else if (mode == 4)
  {
    flashyrolldown();
  }
  else if (mode == 5)
  {
    alternate();
  }
  else if (mode == 6)
  {
    accelerometer();
  }
}
 