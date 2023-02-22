/*!
   @file hardware_test.ino
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/
   Author : @dead10c5 @theDevilsVoice
   Date   : Feb 4, 2023
   Version: 0.1
*/

#include "dead10c5.h"

DeadBadge deadbadge;
SoftwareSerial Serial(RX, TX);

void setup() {
  Serial.begin(9600);
  Serial.println("#######################################");
  Serial.println("# взаимоблокировщики Русский хардбасс #");
  Serial.println("#######################################");
  Serial.println("This badge was a lot of work and a lot of fun for us. Hope you enjoy it!");
  Serial.println("...");
  Serial.print("Version: ");
  Serial.println(VERSION);
  Serial.println("Initializing MPU6050...");
  mpu.Initialize();
  Serial.println("MPU6050 Initialization complete!\nStarting MPU6050 calibration...");
  mpu.Calibrate();
  Serial.println("MPU6050 Calibration complete!");
}

void loop() {

}
