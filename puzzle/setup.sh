#!/usr/bin/env bash

# SPDX-FileCopyrightText: 2023 DE:AD:10:C5 <thedevilsvoice@dead10c5.org>
#
# SPDX-License-Identifier: GPL-3.0-or-later

# Date   : May 31, 2023
# Version: 0.1

set -euo pipefail
# IFS=$'\n\t'

function setup() {
  brew install imagemagick
  brew install ghostscript
}

setup
