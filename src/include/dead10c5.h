/*!
   @file dead10c5.h
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


   Author : @theDevilsVoice https://twitter.com/dead10c5
   Date   : April 3, 2023
   Version: 0.2
*/
#ifndef DEAD10C5_H
#define DEAD10C5

#define VERSION "v0.2 - 03 April 2023 - гопник badge - Путин хуйло"

#include <Arduino.h>        // default library for Arduino
#include <Wire.h>           // used for the I2C communication
#include <SoftwareSerial.h> // used for serial output on the badge

const uint8_t BOTTOM_ROW = PA0; // PB0 on pin2
const uint8_t MIDDLE_ROW = PA1; // PB1 on pin3
const uint8_t TOP_ROW = PB2;    // PB2 on pin5

// MPU6050
const int MPU = 0x68; // MPU6050 I2C address
float AccX, AccY, AccZ;
float GyroX, GyroY, GyroZ;
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;
float roll, pitch, yaw;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;

#endif