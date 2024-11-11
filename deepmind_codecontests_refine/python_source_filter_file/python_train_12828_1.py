# -*- coding: utf-8 -*-
"""
Created on Sat Mar  7 19:30:45 2020

@author: hp
"""

t = int(input())
for j in range(t):
    n,x,y = [int(i) for i in input().split()]
    Sum = x+y
    if(Sum<n):
        first = 1
        last=Sum-1
    else:
        first = Sum-n+1
        if(Sum == 2*n):
            first = n
        last = n
    print(first,last)
    