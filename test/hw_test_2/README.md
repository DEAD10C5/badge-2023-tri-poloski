# HW test 2

- trying out a smaller serial library [ATtinySerialOut](https://github.com/ArminJo/ATtinySerialOut)
- Testing with `wire` only, no dedicated library for MPU6050.
- We used generative AI to come up with this code

```sh
sudo apt install cpplint doxygen -y
sudo avrdude -c usbtiny -p t841 -U flash:w:/tmp/arduino_build_826069/gopnik.ino.hex
```

## Serial Console

You can make a serial connection to the badge using a USB to TTL serial cable.
For example: [USB to TTL Serial Cable](https://www.adafruit.com/product/954)

- Green wire: Connect to serial port, white SCL pin 12
- White wire: Connect to serial port, green SCK pin 9
- Black wire: Connect to Battery, negative (-) pin1
- Red/Orange wire: Battery, positive (+) pin14

You can use `minicom` outside the Arduino IDE to make serial connections if needed.

```sh
TERM=linux minicom -D /dev/ttyUSB0
```
