#include <Arduino.h>
#include <Wire.h>
#define MPU6050_ADDR 0x68
//#define MPU6050_ADDR 0x69


float AccX, AccY, AccZ, MAccX, MAccY, MAccZ;
volatile int mode = 0;
const byte LED_BOTTOM = 10; //PB0 - Bottom
const byte LED_MIDDLE = 9; //PB1 - Middle
const byte LED_TOP = 8; //PB2 - Top
const byte BUTTON = 0; //PA0 - PCINT0



void setup() {

  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B); // Talk to the register 6B
  Wire.write(0x00); // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true); //end the transmission

  //LED Pins
  pinMode(LED_BOTTOM, OUTPUT);
  pinMode(LED_MIDDLE, OUTPUT);
  pinMode(LED_TOP, OUTPUT);

  //Button Pin
  pinMode(BUTTON, INPUT);

  //Set up the interrupt
  cli();
  PCMSK0 |= (1 << PCINT0);
  GIMSK |= (1 << PCIE0);
  sei();

  //Flash the lights so we know setup is done
  lights(1,1,1);
  delay(30);
  lights(0,0,0);
}



void accelerometer() {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 6, true); 
  AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value

  if (AccX < 0) {
    MAccX = abs(AccX);
    AccX = 0;
  }
  else {
    MAccX = 0;
  }

  if (AccY < 0) {
    MAccY = abs(AccY);
    AccY = 0;
  }
  else {
    MAccY = 0;
  }

  if (AccZ < 0) {
    MAccZ = abs(AccZ);
    AccZ = 0;
  }
  else {
    MAccZ = 0;
  }
}



void lights(bool b, bool m, bool t) {
  digitalWrite(LED_BOTTOM, b);
  digitalWrite(LED_MIDDLE, m);
  digitalWrite(LED_TOP, t);
}



ISR (PCINT0_vect) {
  if (digitalRead(BUTTON) == LOW) {
    
    accelerometer();

    //Positive X Wins
    if (
      AccX > MAccX
      && AccX > AccY
      && AccX > MAccY
      && AccX > AccZ
      && AccX > MAccZ
    ) {
      lights(0, 0, 1);
      mode = 0;
    }

    //Negative X Wins
    else if (
      MAccX > AccX
      && MAccX > AccY
      && MAccX > MAccY
      && MAccX > AccZ
      && MAccX > MAccZ
    ) {
      lights(0, 1, 0);
      mode = 1;
    }

    //Positive Y Wins
    else if (
      AccY > MAccY
      && AccY > AccX
      && AccY > MAccX
      && AccY > AccZ
      && AccY > MAccZ
    ) {
      lights(0, 1, 1);
      mode = 2;
    }

    //Negative Y Wins
    else if (
      MAccY > AccY
      && MAccY > AccX
      && MAccY > MAccX
      && MAccY > AccZ
      && MAccY > MAccZ
    ) {
      lights(1, 0, 0);
      mode = 3;
    }

    //Positive Z Wins
    else if (
      AccZ > MAccZ
      && AccZ > AccX
      && AccZ > MAccX
      && AccZ > AccY
      && AccZ > MAccY
    ) {
      lights(1, 0, 1);
      mode = 4;
    }

    //Negative Z Wins
    else if (
      MAccZ > AccZ
      && MAccZ > AccX
      && MAccZ > MAccX
      && MAccZ > AccY
      && MAccZ > MAccY
    ) {
      lights(1, 1, 0);
      mode = 5;
    }
  }
}



void rollup() {
  int del = 20;
  lights(1,0,0);
  delay(del);
  lights(0,1,0);
  delay(del);
  lights(0,0,1);
  delay(del);
  lights(0,0,0);
}



void rolldown() {
  int del = 20;
  lights(0,0,1);
  delay(del);
  lights(0,1,0);
  delay(del);
  lights(1,0,0);
  delay(del);
  lights(0,0,0);
}



void flash() {
  int del = 10;
  lights(1,1,1);
  delay(del);
  lights(0,0,0);
  delay(del);
}



void flashyrollup() {
  int del = 10;
  for (int counter = 0; counter < 4; counter++) {
    lights(1,0,0);
    delay(del);
    lights(0,0,0);
    delay(del);
  }
  for (int counter = 0; counter < 4; counter++) {
    lights(0,1,0);
    delay(del);
    lights(0,0,0);
    delay(del);
  }
  for (int counter = 0; counter < 4; counter++) {
    lights(0,0,1);
    delay(del);
    lights(0,0,0);
    delay(del);
  }
}



void flashyrolldown() {
  int del = 10;
  for (int counter = 0; counter < 4; counter++) {
    lights(0,0,1);
    delay(del);
    lights(0,0,0);
    delay(del);
  }
  for (int counter = 0; counter < 4; counter++) {
    lights(0,1,0);
    delay(del);
    lights(0,0,0);
    delay(del);
  }
  for (int counter = 0; counter < 4; counter++) {
    lights(1,0,0);
    delay(del);
    lights(0,0,0);
    delay(del);
  }
}



void alternate() {
  int del = 30;
  lights(1,0,1);
  delay(del);
  lights(0,1,0);
  delay(del);
}



void loop()
{
  
  if (mode == 0) {
    rollup();
  }
  else if (mode == 1) {
    rolldown();
  }
  else if (mode == 2) {
    flash();
  }
  else if (mode == 3) {
    flashyrollup();
  }
  else if (mode == 4) {
    flashyrolldown();
  }
  else if (mode == 5) {
    alternate();
  }
}
