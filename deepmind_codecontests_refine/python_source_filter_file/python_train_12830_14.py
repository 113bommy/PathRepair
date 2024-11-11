# -*- coding: utf-8 -*-
"""
Created on Tue May 26 19:50:39 2020

@author: Mongia Bros
"""

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    i = n-1
    while (i>0):
        
        if (a[i]<(2+i)):
            break
        i = i-1

    if i==0:
        print(1)
    else:
        print(i+2)