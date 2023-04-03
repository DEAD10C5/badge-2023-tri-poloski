/*!
   @file dead10c5.h
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


   Author : @theDevilsVoice @dead10c5
   Date   : April 4, 2023
   Version: 0.2
*/
#ifndef DEAD10C5_H
#define DEAD10C5
#define VERSION "0.2"

#define RX 8 // serial RX and TX pins.
#define TX 9 // this pin is being used for serial as well?

#include <Arduino.h> // default library for Arduino
#include <Wire.h>    // used for the I2C communication
// #include <TinyMPU6050.h> // maybe this one is smaller/easier to use? There are memory limits
#include <SoftwareSerial.h> // used for serial output on the badge

// pins'n'stuff
const uint8_t DATA_PIN = PA4;  // pin9 SCL/SCK
const uint8_t CLOCK_PIN = PA5; // pin7 SDA

const uint8_t BOTTOM_ROW = PA0; // PB0 on pin2
const uint8_t MIDDLE_ROW = PA1; // PB1 on pin3
const uint8_t TOP_ROW = PB2;    // PB2 on pin5

// MPU6050
float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;
float roll, pitch, yaw;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;

#endif