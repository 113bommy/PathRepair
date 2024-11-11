#!/usr/bin/env python3
# -*- coding: utf-8 -*-

n = int(input())
i = 1
num = [0] * 13

while True:
    cnt = 0
    for j in range(1, i+1):
        if i % j == 0:
            cnt += 1
    if cnt >= 12:
        i += 1
        continue

    if num[cnt] == 0:
        num[cnt] = i

    if num[n] > 0:
        ans = num[n]
        break

    i += 1

print(ans)