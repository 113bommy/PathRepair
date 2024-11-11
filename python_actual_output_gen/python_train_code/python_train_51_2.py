# -*- coding: utf-8 -*-
"""
Created on Sun Dec 22 20:20:19 2019

@author: 93464
"""

n= int(input())
d = dict()
dd = dict()
bb=0
for i in range(n):
    n,k=map(int,input().split())
    if n in d:
        d[n] = d[n]+1
    else:
        d[n] = 1
    if k in dd:
        dd[k] = dd[k]+1
    else:
        dd[k]= 1
for i in d:
    if i in dd:
        bb = bb + d[i]+dd[i]-1
    else:
        pass
print(bb)
        