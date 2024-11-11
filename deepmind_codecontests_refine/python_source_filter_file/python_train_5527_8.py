#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time

(n, M) = (int(i) for i in input().split())
a   = [int(i) for i in input().split()]

start = time.time()

now = 0
x   = []

for i in range(n):
    x.append(a[i] - now)
    now = a[i]

x.append(M-now)

ans = 0
ro  = 0
le  = 0

for i in range(len(x)):
    if i%2 == 1:
        ro  += x[i]
    else:
        ans += x[i]

for i in range(len(x)):
    if x[i] > 1:
        now  = le+ro-1
    if now > ans:
        ans = now

    if i%2 == 1:
        ro  -= x[i]
    else:
        le  += x[i]


print(ans)
finish = time.time()
#print(finish - start)
