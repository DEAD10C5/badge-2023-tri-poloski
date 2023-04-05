/*!
   @file hardware_test.ino
    ____  _____      _    ____    _  ___     ____ ____
   |  _ \| ____|_   / \  |  _ \ _/ |/ _ \ _ / ___| ___|
   | | | |  _| (_) / _ \ | | | (_) | | | (_) |   |___ \
   | |_| | |___ _ / ___ \| |_| |_| | |_| |_| |___ ___) |
   |____/|_____(_)_/   \_\____/(_)_|\___/(_)\____|____/


   Author : @theDevilsVoice https://twitter.com/dead10c5
   Date   : April 3, 2023
   Version: 0.2
*/

#include "dead10c5.h"

void setup()
{
  Serial1.begin(9600); // could probably bump this speed high, not sure why though

  Serial1.print(F("взаимоблокировщики Русский хардбасс: "));
  Serial1.println(VERSION);
  Serial1.println(F("Concept: Yaya Pancho"));
  Serial1.println(F("Translations: @muscovitebob"));
  Serial1.println(F("Artwork: @p0lr_"));
  Serial1.println(F("Hardware/software: @p0lr_ @thedevilsvoice"));
  delay(1000);

  pinMode(BOTTOM_ROW, OUTPUT);
  pinMode(MIDDLE_ROW, OUTPUT);
  pinMode(TOP_ROW, OUTPUT);

  TinyWireM.begin();
  timeNow = millis();

}

void loop()
{

  digitalWrite(BOTTOM_ROW, HIGH);
  delay(1000);
  digitalWrite(BOTTOM_ROW, LOW);
  delay(1000);

  digitalWrite(MIDDLE_ROW, HIGH);
  delay(1000);
  digitalWrite(MIDDLE_ROW, LOW);
  delay(1000);

  digitalWrite(TOP_ROW, HIGH);
  delay(1000);
  digitalWrite(TOP_ROW, LOW);
  delay(1000);

    if (millis() - timeNow >= 500) {
        if (!slavePresent) {                                            // determine if slave joined the I2C bus
            TinyWireM.beginTransmission(SLAVE_ADDR);                    // begin call to slave
            if (TinyWireM.endTransmission() == 0) slavePresent = true;  // if responds - mark slave as present
        } else {                                                        // slave found on I2C bus
            TinyWireM.beginTransmission(SLAVE_ADDR);                    // begin call to slave
            TinyWireM.write(data);                                      // send a single byte to slave
            TinyWireM.endTransmission();                                // end call to slave
            data += 1;                                                  // increment data to send
        }
        timeNow = millis();                                             // mark current time (in mS)
    }
}