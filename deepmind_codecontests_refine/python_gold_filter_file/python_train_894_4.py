#! /usr/bin/env python3

import math

n = int(input())

for num in range(1,n):
    if 2* num > n and math.gcd(n - num, num) == 1:
        print(n - num, num)
        break
