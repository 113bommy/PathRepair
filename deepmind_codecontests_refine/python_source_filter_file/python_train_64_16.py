# -*- coding: utf-8 -*-
"""
Created on Fri Feb 16 21:31:15 2018

@author: Anuroop Behera
"""

n = int(input())
a = input().split()
for i in range(len(a)):
    a[i] = int(a[i])
if a[n-1] <= 1000000/2:
    print(a[n-1]-1)
elif a[0] > 1000000/2:
    print(1000001-a[0]-1)
else:
    for i in range(len(a)):
        if a[i] >=500000:
            break
    print(max(a[i-1],1000001-a[i])-1)
    