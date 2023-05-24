# Test

## Chip Setup

- Install Arduino IDE.
- Click `file -> Preferences` (on MacOS `Arduino IDE -> Settings`)
- Add this to `Additional Boards manager URLS`: `http://drazzy.com/package_drazzy.com_index.json`
- Click `ok`
- Click on `Tools -> Boards Manager` (on MacOS `Tools -> Board -> Boards Manager`) and make sure
  `ATTinyCore` is installed.
  - Install version 1.5.2 or later.
- Click on `Tools -> Board -> ATTinyCore` and select one of the ATTiny 441/841 board types.
- Click on `File -> Open` and select the `test/accelerometer_test.ino file` in this repo
- A dialog appears asking if you want to create a folder and move the file, press `OK`
- Click on `Sketch -> Include Library -> Manage Libraries`. In the search bar, type "TinyMPU6050"
  and click the `INSTALL` button
- Start a build by pressing the button with the checkmark in the upper left of the window

### Install Libraries

- Save these zip files to the `Arduino/libraries` folder.
  - In your home directory if using Linux.
- Unzip them.
- You might need to restart KiCAD.

- [ATTinyCore Universal](https://github.com/SpenceKonde/ATTinyCore)
- [TinyMPU6050](https://github.com/gabriel-milan/TinyMPU6050)

## Burn Bootloader

- Use ARduino IDE 2.0.4 or later
- Add the "Arduino AVR Boards" from board manager.
- Upload the `src/ArduinoISP` sketch to the Arduino UNO.
- Connect board and "get board info", you should see serial number.

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

- [More information about PlatformIO Unit Testing](https://docs.platformio.org/page/plus/unit-testing.html)

```sh
platformio pkg install -l ArduinoNative
platformio pkg install -l TinyWireM
```
