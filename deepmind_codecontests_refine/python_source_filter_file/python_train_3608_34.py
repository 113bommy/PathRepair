#! python3
# 962A_equator.py

import math

n = int(input())
a = [int(x) for x in input().split(' ')]

half = sum(a)/2

tmp = 0
for i in range(n):
    tmp += a[i]
    if tmp >= half:
        print(i)
        break
