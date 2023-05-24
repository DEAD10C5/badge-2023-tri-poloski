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



![Board Settings](images/20230513_213218.jpg?raw=true)
