#!/usr/bin/env python3
n = int(input())

if n == 2:
    print(1)
    exit()

p = 2
pp = 1
i = 1
while True:
    c = p + pp
    if c > n:
        print(i)
        exit()
    i += 1
    pp = p
    p = c
