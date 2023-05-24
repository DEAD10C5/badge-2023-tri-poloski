#include <TinyWire.h>

#define led_pin 1
#define I2C_SLAVE_ADDR  0x11  


void setup() {
    // config led_pin as Output for driving an LED
    pinMode(led_pin, OUTPUT);

    // config TinyWire library for I2C slave functionality
    TinyWire.begin( I2C_SLAVE_ADDR );
    // sets callback for the event of a slave receive
    TinyWire.onReceive( onI2CReceive );
}

void loop() {

}

/*
I2C Slave Receive Callback:
Note that this function is called from an interrupt routine and shouldn't take long to execute
*/
void onI2CReceive(int howMany){
    // loops, until all received bytes are read
    while(TinyWire.available()>0){
        // toggles the led everytime, when an 'a' is received
        if(TinyWire.read()=='a') digitalWrite(led_pin, !digitalRead(led_pin));
    }
}