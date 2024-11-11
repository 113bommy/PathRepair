# -*- coding: utf-8 -*-
"""
Created on Tue Nov 28 20:27:33 2017

@author: alter027
"""
import sys

d=[[0 for col in range(500)] for row in range(500)]
v=[0]*500
n, m=map(int, input().split())
for i in range(m):
    x, y=map(int, input().split())
    x -= 1
    y -= 1
    d[x][y] = d[y][x]=1
q = [0]
l = 0

while l < len(q):
    for i in range(1,n):
        if d[0][n-1] != d[q[l]][i] and v[i] == 0 :
            v[i] = v[q[l]] + 1
            q.append(i)
    l += 1

if v[n-1] == 0:
    print(-1)
else:
    print(v[n-1])
            