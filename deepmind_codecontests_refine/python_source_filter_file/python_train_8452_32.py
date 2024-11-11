#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: bekzat
"""


t = int(input())
ans = []
for number in range(t):
    n, x, a, b = map(int, input().split())
    if (n - 1 == abs(a - b)):
        ans.append(n - 1)
        continue
    if (x == 0):
        ans.append(abs(a - b))
        continue
    max1 = max(a,b)
    min1 = min(a,b)
    if (min1 - x <= 0):
        x = x - (min1 - 1)
        min1 = 1
        if (max1 + x >= n):
            max1 = n
        else:
            max1 = max1 + x
            ans.append(abs(max1 - min1))
    else:
        min1 = min1 - x
        x = 0
        ans.append(abs(max1 - min1))
        
for item in ans:
    print(item)