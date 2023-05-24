1. move the MPU or the battery so it is easier to insert the coin cell
2. The mounting hole is missing from the board. (1, 2, or 3 holes?)
3. Can the chip be programmed while it is attached to the board? Depends on connections?
4. the switch is not needed with "regular" LED. Could still be used for blink patterns?
5. Break out all the pins from the chip from now on. That way you can still prototype
   if there is some issue with the circuits.

we can use the "optiboot" core and program the chip using USB to serial converter.

## Burn Bootloader

- Use ARduino IDE 2.0.4 or later
- Add the "Arduino AVR Boards" from board manager.
- Upload the `src/ArduinoISP` sketch to the Arduino UNO.
- Connect board and "get board info", you should see serial number.

Pin details for ISP header:
// By default, the hardware SPI pins MISO, MOSI and SCK are used to communicate
// with the target. On all Arduinos, these pins can be found
// on the ICSP/SPI header:
//
//               MISO °. . 5V (!) Avoid this pin on Due, Zero...
//               SCK   . . MOSI
//                     . . GND
//
// On some Arduinos (Uno,...), pins MOSI, MISO and SCK are the same pins as
// digital pin 11, 12 and 13, respectively. That is why many tutorials instruct
// you to hook up the target to these pins. If you find this wiring more
// practical, have a define USE_OLD_STYLE_WIRING. This will work even when not
// using an Uno. (On an Uno this is not needed).

Choose Bootloader UART1 if you are using ISP header programming since the TX is on pin 8 and the RX is on pin 9.

const uint8_t  DATA_PIN   = PA5; // pin 8
const uint8_t  CLOCK_PIN  = PA4; // SCL pin 9

Choose board ATtiny441/841 with Optiboot. This allows programming via USB to Serial cable not just ISP header.
Programmer: ATtiny as ISP (ATtiny Core)

For USB to TTL, while viewing the BACK of the board:

- Green/Grey wire: TX out of the USB port, RX on the chip, connect to bottom center pin on ISP header next to green/grey.
- White wire: RX into USB port, TX on the chip, connect bottom left (below power).
- Black wire: Connect to negative (-) port on back, top right of ISP header.
- Red/Orange wire: Connect to (+) port on the back, top l;eft of ISP header.

Connect board, burn bootloader from board menu.
Then you can start uploading sketches

## Programming

- [Add the ATTINY 841 using these directions](https://github.com/SpenceKonde/ATTinyCore/blob/v2.0.0-devThis-is-the-head-submit-PRs-against-this/Installation.md#boards-manager-installation)
- [SparkFun FT231X Breakout](https://www.sparkfun.com/products/13263)

### Install Libraries

- [TinyMPU6050](https://github.com/gabriel-milan/TinyMPU6050)

## Serial Console

You can make a serial connection to the badge using a USB to TTL serial cable.
For example: [USB to TTL Serial Cable](https://www.adafruit.com/product/954)

There is a six pin (2x3) header on the right side of the board when viewed from the back.

| wire | description |
| --- | --- |
| Black GROUND wire | Connect to Battery port, negative (-) port.
| Red/Orange POWER wire | Connect to Battery port, positive (+) port. |
| Green wire | Connect to serial port. |
| White wire | Connect to serial port, left side looking at back. |

pin13 SCK
pin12 MISO
pin11 MOSI
pin10 SS

You can make a serial connection to the badge using a USB to TTL serial cable.
For example: [USB to TTL Serial Cable](https://www.adafruit.com/product/954)

- Green wire: Connect to serial port, white SCL pin 12
- White wire: Connect to serial port, green SCK pin 9
- Black wire: Connect to Battery, negative (-) pin1
- Red/Orange wire: Battery, positive (+) pin14

TERM=linux minicom -D /dev/ttyUSB0

## Flashing

- Green wire: Connect to serial port, white TX pin 8
- White wire: Connect to serial port, green RX pin 9
- Black wire: Connect to Battery pin1, negative (-) port.
- Red/Orange wire: pin14 (+)

## PlatformIO

This directory is intended for PlatformIO Unit Testing and project tests.

Unit Testing is a software testing method by which individual units of
source code, sets of one or more MCU program modules together with associated
control data, usage procedures, and operating procedures, are tested to
determine whether they are fit for use. Unit testing finds problems early
in the development cycle.

More information about PlatformIO Unit Testing:
- https://docs.platformio.org/page/plus/unit-testing.html

```sh
platformio pkg install -l ArduinoNative
platformio pkg install -l TinyWireM
```
