#!/usr/bin/env python3

import sys
from math import log

m = int(input())

number_of_zeroes = 0
for i in range(5, 100001, 5):
    k = i
    while k % 5 == 0:
        number_of_zeroes += 1
        k //= 5
    if number_of_zeroes == m:
        print(5)
        for j in range(0, 5):
            print(i + j, end=' ')
        sys.exit(0)
    elif m < number_of_zeroes:
        break
print(0)
