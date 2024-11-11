# -*- coding: utf-8 -*-
"""
Created on Wed Jul 10 19:18:07 2019

@author: avina
"""

n, m = map(int, input().split())
l = list(map(int, input().split()))

a = l[0]-1

for i in range(1,m):
    if l[i] - l[i-1]>=0:
        a+= l[i] - l[i-1]
    else:
        a+= n-m + l[i] 
print(a)