#!/usr/bin/python3

import math
import sys
input = sys.stdin.buffer.readline

T = int(input())
for _ in range(1, T + 1):
    n = int(input())
    numbers = [int(x) for x in input().split()]
    m, d = numbers[0], 0
    for i in range(1, n):
        m = max(m, numbers[i])
        d = max(d, m-numbers[i])
    if d == 0:
        print(0)
        continue
    print(math.ceil(math.log2(d)) + 1)
