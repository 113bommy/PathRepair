# -*- coding: utf-8 -*-
"""
Created on Sat Feb  9 18:25:31 2019

@author: avina
"""

n = int(input())

L = []
count = 0
for i in range(n):
    l = list(input())
    L.append(l)
m = len(l)
for i in range(1,n-1):
    for j in range(1,m-1):
        if L[i][j] == L[i+1][j-1] == L[i-1][j+1] == L[i-1][j-1] == L[i+1][j+1] == 'X':
            count+=1
print(count)