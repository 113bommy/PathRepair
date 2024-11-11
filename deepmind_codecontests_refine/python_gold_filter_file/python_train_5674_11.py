#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time

(n, m) = (int(i) for i in input().split())
A = [ 0 for i in range(m) ]

for i in range(m):
    buf = [int(j) for j in input().split()]
    max = -1
    for j in range(n):
        if max < buf[j]:
            max  = buf[j]
            A[i] = j + 1

start = time.time()

ans = False
max = -1

for i in set(A):
    s = sum([1 for j in A if j == i])
    if s > max:
        ans = i
        max = s
    if ans != False and s == max:
        if ans > i:
            ans = i
print(ans)
finish = time.time()
#print(finish - start)
