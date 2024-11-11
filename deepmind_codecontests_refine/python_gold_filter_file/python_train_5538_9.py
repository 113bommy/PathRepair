#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time


q   = int(input())
ans = []

start = time.time()

for i in range(q):
    (h, n) = (int(j) for j in input().split())
    p = [int(j) for j in input().split()]
    a = 0
    now = 1
    while( now < n ):
        if now == n-1:
            if p[now] > 1:
                a   += 1
            now +=1
        elif p[now]-1 != p[now+1]:
            a += 1
            now += 1
        else:
            now += 2
    ans.append(a)

for i in range(q):
    print(ans[i])
finish = time.time()
#print(finish - start)
