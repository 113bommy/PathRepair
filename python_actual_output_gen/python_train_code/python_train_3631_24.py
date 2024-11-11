# -*- coding: utf-8 -*-
"""
Created on Sun Nov 29 21:48:03 2020

@author: harshvardhan
"""

n,m = map(int,input().split())
dc = {}
for i in range(m):
    a,b = input().split()
    dc[a]=b
words = input().split()

for i in words:
    if len(i)<len(dc[i]):
        print(i,end=" ")
    else:
        print(dc[i],end = " ")