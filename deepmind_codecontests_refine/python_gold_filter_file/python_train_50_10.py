# -*- coding: utf-8 -*-
"""
Created on Sat Nov  7 19:55:28 2020

@author: 86177
"""

n,m=[int(x) for x in input().split()]
w=[]
for i in range(n):
    c=[int(x) for x in input().split()]
    for x in c[1:]:
        w.append(x)

a=len(set(w)) 
if a == m:
    print("YES")
else:
    print('NO')