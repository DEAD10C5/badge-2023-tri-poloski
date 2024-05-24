#!/usr/bin/env bash

# SPDX-FileCopyrightText: 2023 DE:AD:10:C5 <thedevilsvoice@dead10c5.org>
#
# SPDX-License-Identifier: GPL-3.0-or-later

# wrote this so I wouldn't have to click all the puzzle footprints

# this will preserve the leading whitespace when line gets echoed
IFS=''

# reset the counter each time just to keep the numbers from getting ridiculously large
num=0
while read line; do num=$((++num)) && echo $line|sed "s/fp_text reference \"olive/&"$num"/"; done < adidas.kicad_pcb  > test/test.out
num=0
while read line; do num=$((++num)) && echo $line|sed "s/fp_text reference \"melon1/&"$num"/"; done < test/test.out > test/test2.out
num=0
while read line; do num=$((++num)) && echo $line|sed "s/fp_text reference \"APPLE2/&"$num"/"; done < test/test2.out > test/test3.out
num=0
while read line; do num=$((++num)) && echo $line|sed "s/fp_text reference \"comm/&"$num"/"; done < test/test3.out > test/test.kicad_pcb

