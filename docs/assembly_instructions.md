# Assembly

## Parts

- 2 switches (need to order 400)
- battery clips
- batteries
- SAO headers

## Assembly Steps

- Solder a [Keystone SMT 3002 coin cell retainer](https://www.digikey.com/en/products/detail/keystone-electronics/3002/227444)
  to the back middle of the board.
- (OPTIONAL) solder a 2×3 Pin 6 Pin With Polarizing Key. The connector should be oriented as shown in the
  [AND!XOR SAO Reference Designs](https://github.com/DEAD10C5/badge-project-template/blob/main/docs/shitty_add_ons.md)

## Flashing

* [SparkFun AVR Pocket Programmer](https://learn.sparkfun.com/tutorials/pocket-avr-programmer-hookup-guide/all)
* Set "Tools -> Programmer" to "USBtinyASP (FAST)"
* Means you don't need a boot loader. Saves some memory.
