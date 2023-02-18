# Docs go here

Generate the Gerbers like so:
`bash kicad-exports -c docs/gerbers.kibot.yaml -d docs -b kicad/adidas.kicad_pcb -e kicad/adidas.kicad_sch`

## Routing

[FreeRouting](https://github.com/freerouting/freerouting)

## Setup

- Install Arduino IDE.
- Click `file -> Preferences`
- Add this to `Additional Boards manager URLS`: `http://drazzy.com/package_drazzy.com_index.json`
- Click `ok`
- Click on `Tools -> Boards Manager` and make sure `ATTinyCore` is installed.
  - Install version 1.5.2 or later.
- Select one of the ATTiny 441/841 board types.

## Libraries

- [ATTinyCore Universal](https://github.com/SpenceKonde/ATTinyCore)
- [TinyMPU6050](https://github.com/gabriel-milan/TinyMPU6050)
