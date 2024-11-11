#!/usr/bin/env python3
import sys
input = sys.stdin.readline

n = int(input())
increasing = []
decreasing = []
for _ in range(n):
    s = input().rstrip()
    minima = 0
    fin = 0
    for ch in s:
        if ch == ")":
            fin -= 1
            if fin < minima:
                minima = fin
        else:
            fin += 1
    if fin >= 0:
        increasing.append((minima, fin))
    else:
        decreasing.append((minima - fin, fin))

increasing.sort(reverse=True)
decreasing.sort()

current = 0
for minima, diff in increasing:
    if current + minima < 0:
        print("No")
        exit()
    current += diff
for minima, diff in decreasing:
    if current + minima < 0:
        print("No")
        exit()
    current += diff
if current != 0:
    print("No")
else:
    print("Yes")