# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

n,m,h = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
h = [[] for i in range(n)]
for i in range(n):
    h[i] = [int(i) for i in input().split()]
    for j in range(m):
        if(h[i][j]>0):
            h[i][j] = max(a[j],b[i])
for i in range(n):
    for j in range(m):
        print(h[i][j],end=' ')
    print()
    