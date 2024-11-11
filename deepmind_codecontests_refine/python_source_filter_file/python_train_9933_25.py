# -*- coding: utf-8 -*-
"""
Created on Sun May 26 01:16:31 2019

@author: avina
"""

n,m = map(int, input().split())
l = list(map(int, input().split()))

f = sum(l[:m])
k = [f]

for i in range(1,n-m):
    f = f - l[i-1] + l[i+m-1]
    k.append(f)
a = min(k)
print(k.index(a)+1)