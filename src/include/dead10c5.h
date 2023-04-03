/*!
   @file dead10c5.h
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


   Author : @theDevilsVoice @dead10c5
   Date   : Feb 4, 2023
   Version: 0.1
*/
#ifndef DEAD10C5_H
#define DEAD10C5
#define VERSION "0.1"

/*
Define the RX and TX pins. Choose any two pins that are unused.
Try to avoid D0 (pin 5) and D2 (pin 6) if you plan to use I2C.
*/
#define RX 8
#define TX 9

#include <Arduino.h> // default library for Arduino
//#include <Wire.h> // used for the I2C communication
//#include <TinyMPU6050.h> // maybe this one is smaller/easier to use? There are memory limits
#include <SoftwareSerial.h> // used for serial output on the badge

// pins'n'stuff
const uint8_t  DATA_PIN   = PA2; // pin8 RX
const uint8_t  CLOCK_PIN  = PA4; // SCL pin9 TX

const uint8_t  BOTTOM_ROW = PB0; // PB0 on pin2
const uint8_t  MIDDLE_ROW = PB1; // PB1 on pin3
const uint8_t  TOP_ROW = PB2; // PB2 on pin5

// MPU6050
float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;
float roll, pitch, yaw;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;

#endif