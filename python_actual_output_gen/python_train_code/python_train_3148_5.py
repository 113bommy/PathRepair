# -*- coding: utf-8 -*-
"""
Created on Sat Feb 16 23:41:17 2019

@author: avina
"""

n,m, k = map(int, input().strip().split())

l = list(map(int, input().strip().split()))

for i in range(n-1):
    l[i] = l[i+1] - l[i]
l[n -1] = m - l[n-1]
l.sort()
sums = 0
for i in range(n - k):
    sums+=l[i] 
print(sums +  k)