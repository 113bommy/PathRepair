# -*- coding: utf-8 -*-
"""
Created on Thu May 23 10:17:14 2019

@author: avina
"""

n,h,m = map(int, input().split())
l = list(map(int, input().split()))
l2 = list(map(int, input().split()))

k = []
for i in range(n):
    e = list(map(int,input().split()))
    k.append(e)

for i in range(n):
    for j in range(h):
        if k[i][j] == 1:
            k[i][j] = min(l[j],l2[i])
            print(k[i][j], end = ' ')
        else:
            print(k[i][j], end= ' ')
    print()
        
