# C++ Code

- [How to program the ATtiny 841 using the Arduino IDE](https://www.youtube.com/watch?v=TyJQtaTvj3Q)
- [ATTinyCore Universal](https://github.com/SpenceKonde/ATTinyCore)
- [I2C Device Library](http://www.i2cdevlib.com/)

## ATTiny841

- 8k Flash, 512b EEPROM, 512b SRAM
- Optiboot bootloader support - program over serial! (takes a bit more memory)
- Dual hardware UARTs
- Hardware SPI
- Hardware I2C slave (I2C master is handled with a software implementation)
- SIX PWM outputs
- ADC on all pins
- Two on-chip analog comparators
- Compatible with Arduino IDE 1.6.5 and higher - we recommend the latest 1.8.x release.
- 8mhz (internal), up to 16mhz with external crystal. (20mhz seems to work @ 5v and room temperature, despite being out of spec)

## MPU6050

- [Arduino and MPU6050 Accelerometer and Gyroscope Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-and-mpu6050-accelerometer-and-gyroscope-tutorial/)
