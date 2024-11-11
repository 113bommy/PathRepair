#!/usr/bin/env python3
import sys

y = int(input())

def check(year):
    sums = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for num in str(year):
        sums[int(num)] += 1
    return sum([1 for i in sums if i not in [0, 1]]) == 0

for i in range(y + 1, 9000+1):
    if check(i):
        print(i)
        break
