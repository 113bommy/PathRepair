#!/usr/bin/env python3
s = int(input())
y = (s % 10**9 - 10**9) % 10**9
x = (s + y) // 10**9
print(0, 0, 1, 10**9, x, -y)
