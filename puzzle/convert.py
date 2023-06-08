# SPDX-FileCopyrightText: 2023 DE:AD:10:C5 <thedevilsvoice@dead10c5.org>
#
# SPDX-License-Identifier: GPL-3.0-or-later


class MyCounter:

    COMMA = "U+2C"
    APPLE = "https://graphemica.com/🍎"  # U+1F34E
    MELON = "https://graphemica.com/🍈"  # U+1F348
    OLIVE = "https://graphemica.com/🫒"  # U+1FAD2

    ROW1 = "🍈🫒🫒🍈🫒,🍈🫒🍎🍈🍎,🍈🫒🍎🫒🍎,🍈🫒🍈🍎,🍎🍎🍎🍈,🍈🫒🍎🍎🍎,🍈🫒🍎🍈🍎,🍈🍈🫒🍎🫒,🍈🫒🍈🍎🍈,🍈🍈🫒🫒🍎,🍈🫒🍈🍎🍈,🍈🫒🍈🍎,🍈🫒🍈🍎🍈,🍈🍈🫒🍎🫒,🍈🫒🍎🫒🍎,🍈🫒🍈🍎,🍈🍈🫒🫒🍎,🍈🍈🫒🍈🫒,"
    ROW2 = "🍈🍈🫒🍎🍎,🍈🫒🍈🍎,🍈🍈🫒🍎🍈,🍈🫒🍎🫒🍎,🍈🫒🍎🫒🍎,🍈🍈🫒🫒🍎,🍈🫒🍈🍎,🍈🫒🍈🍎🍎,🍈🍈🍈🫒🫒,🍈🍈🫒🍎🍎,🍈🫒🍈🍎,🍈🫒🍎🫒🍎,🍈🍈🍈🫒🍈,🍈🍈🫒🍈🫒,🍈🍈🫒🫒🫒,🍈🍈🍈🫒🍈,🍈🫒🍎🫒🍎,🍈🫒🍈🍎,"
    ROW3 = "🍈🍈🫒🍎🍎,🍈🫒🍎🍈🍎,🍈🫒🍎🫒🍎,🍈🫒🍈🍎,🍈🫒🍎🍎🍎,🍈🫒🍎🫒🍎,🍈🍈🍈🍈🍈,🍈🫒🍈🍎,🍈🫒🫒🍈🫒,🍈🍈🫒🍈🫒,🍈🫒🍈🍎,🍈🫒🍈🍎🍈,🍈🍈🫒🍎🫒,🍈🍈🫒🍎🫒,🍈🫒🍎🍎🫒,🍈🍈🍈🫒🍈,🍈🫒🍎🫒🍎,🍈🫒🍈🍎,"
    ROW4 = "🍈🫒🍈🍎🍈,🍈🍈🫒🍎🍎,🍈🫒🍈🍎,🍈🍈🫒🍎🍎,🍈🫒🍎🍈🍎,🍈🫒🍎🫒🍎,🍈🫒🍈🍎,🍈🫒🍎🫒🍎,🍈🍈🫒🫒🍎,🍈🫒🍎🫒🍈,🍈🫒🍈🍎,🍈🫒🍎🍈🫒,🍈🍈🫒🍈🫒,🍈🍈🫒🫒🫒,🍈🍈🫒🫒🫒,🍈🍈🫒🍈🫒,🍈🍈🍈🫒🍎,🍈🫒🍈🍎,"
    ROW5 = "🍈🍈🫒🍎🍎,🍈🫒🍎🍈🍎,🍈🫒🍎🫒🍎,🍈🫒🍈🍎,🍈🫒🍎🍈🍎,🍈🫒🍎🍎🫒,🍈🍈🫒🍎🍈,🍈🍈🫒🍎🍎,🍈🍈🫒🍈🫒,🍈🍈🫒🍎🫒,🍈🍈🍈🍈🍈"

    TOTAL_COUNT = 0
    COMMA_COUNT = 0
    APPLE_COUNT = 0
    MELON_COUNT = 0
    OLIVE_COUNT = 0
    UNKNOWN_COUNT = 0

    def update_counts(self, current_symbol):
        print("Found {}".format(current_symbol))
        self.TOTAL_COUNT = self.TOTAL_COUNT + 1
        if current_symbol == self.COMMA:
            self.COMMA_COUNT = self.COMMA_COUNT + 1
        elif current_symbol == "U+1F34E":
            self.APPLE_COUNT = self.APPLE_COUNT + 1
        elif current_symbol == "U+1F348":
            self.MELON_COUNT = self.MELON_COUNT + 1
        elif current_symbol == "U+1FAD2":
            self.OLIVE_COUNT = self.OLIVE_COUNT + 1
        else:
            self.UNKNOWN_COUNT = self.UNKNOWN_COUNT + 1

    def show_totals(self):
        print("Total count: {}".format(self.TOTAL_COUNT))
        print("Comma count: {}".format(self.COMMA_COUNT))
        print("Apple count: {}".format(self.APPLE_COUNT))
        print("Melon count: {}".format(self.MELON_COUNT))
        print("Olive count: {}".format(self.OLIVE_COUNT))
        print("Unknown symbol count: {}".format(self.UNKNOWN_COUNT))


my_counter = MyCounter()

for item in my_counter.ROW1:
    current = f"U+{ord(item):X}"
    my_counter.update_counts(current)

for item in my_counter.ROW2:
    current = f"U+{ord(item):X}"
    my_counter.update_counts(current)
for item in my_counter.ROW3:
    current = f"U+{ord(item):X}"
    my_counter.update_counts(current)
for item in my_counter.ROW4:
    current = f"U+{ord(item):X}"
    my_counter.update_counts(current)
for item in my_counter.ROW5:
    current = f"U+{ord(item):X}"
    my_counter.update_counts(current)

my_counter.show_totals()
