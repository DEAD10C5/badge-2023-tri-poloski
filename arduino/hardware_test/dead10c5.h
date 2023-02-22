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
#define RX 3
#define TX 10

#include <Arduino.h> // default library for Arduino
#include <Wire.h> // used for the I2C communication
#include <TinyMPU6050.h> // maybe this one is smaller/easier to use? There are memory limits
#include <SoftwareSerial.h> // used for serial output on the badge

// pins'n'stuff
const uint8_t  DATA_PIN   = PA2;
const uint8_t  CLOCK_PIN  = PA3;

MPU6050 mpu(Wire);

#endif