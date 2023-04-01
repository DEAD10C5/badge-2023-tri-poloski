# Public Docs

## Soldering

- solder a (B3F-1000 Omron Switch](https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf) to the front or back of the board in the bottom center.

## Serial

You can make a serial connection to the badge using a USB to TTL serial cable.

For example: [USB to TTL Serial Cable](https://www.adafruit.com/product/954)

- Green wire: Connect to serial port, right side looking at back.
- White wire: Connect to serial port, left side looking at back.
- Black wire: Connect to Battery port, negative (-) port.
- Red/Orange wire: Do not connect! This is +5V but the board is at +3V.

## Programming

We used an Arduino UNO as an ISP to program the attiny84 chip on the badge.

[Set up the programming environment](http://highlowtech.org/?p=1695)

We did a "6 way" header similar to the one described at the link below.

[About ISP headers](http://www.batsocks.co.uk/readme/isp_headers.htm)
