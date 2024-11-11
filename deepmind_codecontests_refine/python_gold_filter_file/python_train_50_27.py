# -*- coding: utf-8 -*-
"""
Created on Mon Nov  9 15:27:05 2020

@author: zyc
"""

n,m=input().split(' ')
n=int(n)
m=int(m)
s=[]
for i in range(n):
    t=[int(x) for x in input().split(' ')]
    for i in range(len(t)-1):
        s.append(t[i+1])
if len(set(s))==m:
    print('YES')
else:
    print('NO')
    