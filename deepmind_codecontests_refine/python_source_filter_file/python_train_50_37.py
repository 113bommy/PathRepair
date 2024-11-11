# -*- coding: utf-8 -*-
"""
Created on Sun Nov  8 10:05:21 2020

@author: HUAWEI Mate 40 Pro
"""

m, n = map(int,input().split())
l = [False for i in range(0,n)]

for i in range(0,m):
    for j in [int(x) for x in input().split()]:
        if not l[j-1]:
            l[j-1] = True
print(["NO","YES"][min(l)])