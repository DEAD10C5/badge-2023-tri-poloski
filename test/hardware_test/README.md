# Dev/Test Notes

```sh
platformio pkg install -l ArduinoNative
platformio pkg install -l TinyWireM
```

- [TinyMPU6050](https://github.com/gabriel-milan/TinyMPU6050)

## Flashing the Board

Connect the pins.

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
