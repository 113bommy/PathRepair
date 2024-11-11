#!/usr/bin/env python
# -*- coding: utf-8 -*-

while True:
    N,M,P = map(int,input().split(" "))
    if N == 0 and M == 0 and P == 0:
        break
    count = 0
    for i in range(N):
        x = int(input())
        count += x
        if i + 1 == M:
            hitman = x
    if hitman == 0:
        print(0)
    else:
        print(int((count*100)*((100-P)/100)/hitman))