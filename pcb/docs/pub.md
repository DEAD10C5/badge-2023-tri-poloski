# Public Docs

## Soldering

- Solder a (B3F-1000 Omron Switch](https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf)
  to the back of the board in the bottom center. The button is used to toggle between
  light pattern modes.
- Solder a [Keystone SMT 3002 coin cell retainer](https://www.digikey.com/en/products/detail/keystone-electronics/3002/227444)
  to the back middle of the board.
- (OPTIONAL) solder a 2×3 Pin 6 Pin With Polarizing Key. The connector should be oriented as
  shown in the [AND!XOR SAO Reference Designs](https://github.com/DEAD10C5/badge-project-template/blob/main/docs/shitty_add_ons.md)

## Serial

You can make a serial connection to the badge using a USB to TTL serial cable.

For example: [USB to TTL Serial Cable](https://www.adafruit.com/product/954)

- Green wire: Connect to serial port, right side looking at back.
- White wire: Connect to serial port, left side looking at back.
- Black wire: Connect to Battery port, negative (-) port.
- Red/Orange wire: Do not connect! This is +5V but the board is at +3V.
