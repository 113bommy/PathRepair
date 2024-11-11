#!/usr/bin/env python3
n = input()
print((len(n) - 1) * 9 + int(n[0]) - 1 * (n != "9" * len(n)))
