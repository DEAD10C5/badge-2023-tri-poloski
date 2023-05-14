# Docs go here

Generate the Gerbers like so:
`bash kicad-exports -c docs/gerbers.kibot.yaml -d docs -b kicad/adidas.kicad_pcb -e kicad/adidas.kicad_sch`

## Routing

1. From the main KiCAD window, select the "Plugin and Contect Manager"
2. Install the "Freerouting" plug in.
3. Install the "PCBWay plug in for KiCAD"

You can also use the older [FreeRouting](https://github.com/freerouting/freerouting) tool.

```sh
locate freeRouting.jar
java -jar /opt/layout/bin/freeRouting.jar
```

## Chip Setup

- Install Arduino IDE.
- Click `file -> Preferences`
- Add this to `Additional Boards manager URLS`: `http://drazzy.com/package_drazzy.com_index.json`
- Click `ok`
- Click on `Tools -> Boards Manager` and make sure `ATTinyCore` is installed.
  - Install version 1.5.2 or later.
- Select one of the ATTiny 441/841 board types.

![Board Settings](images/20230513_213218.jpg?raw=true)

## Libraries

- Save these zip files to the `Arduino/libraries` folder.
- Unzip them.
- You might need to restart KiCAD.

- [ATTinyCore Universal](https://github.com/SpenceKonde/ATTinyCore)
- [TinyMPU6050](https://github.com/gabriel-milan/TinyMPU6050)

## Flashing the Bootloader

## Flashing new Software

- Use [SDK08 Test Clip](https://www.amazon.com/SDK08-Ultra-Small-Micro-Adapters/dp/B0B4DHVDRV/) to connect to pins on chip.
- You might be able to use the other pin copnnectors on the board but it is a lot flakier than the clips.

![Chip pins](https://github.com/DEAD10C5/badge-project-template/blob/main/pcb/docs/images/clip.jpg?raw=true)

![chip](https://github.com/DEAD10C5/badge-2023-tri-poloski/blob/main/pcb/docs/images/T-U23W61080A/BACK-ATTTINY.png?raw=true)
