#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jun 15 16:58:00 2019

@author: YudNK
"""
import bisect as bs

N, Q = map(int, input().split())
E = []
for i in range(N):
    s, t, x = map(int, input().split())
    a = [s - x, t - x, x] #イベント
    E.append(a)
E.sort(key = lambda x: x[2])
D = []
for i in range(Q):
    D.append(int(input()))

ans = [-1]*Q
check = [-1]*Q

for e in E:
    l = bs.bisect_left(D, e[0])
    r = bs.bisect_left(D, e[1])
    while l != r:
        if check[l] == -1:  
            ans[l] = e[2]
            check[l] = r
            l += 1
        else:
            l = check[l]
        
[print(i) for i in ans]