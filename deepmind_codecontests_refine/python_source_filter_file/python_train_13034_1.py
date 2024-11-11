# -*- coding: utf-8 -*-
"""
Created on Thu Jul 23 06:28:25 2020

@author: Dark Soul
"""

t=int(input(''))
mat=[]
for i in range(t):
    input('')
    mat.append(list(map(int, input().split())))
for i in range(t):
    y=mat[i]
    s=sum(y)
    x=0
    for i in range(len(y)):
        x=x^y[i]
    print(2)
    print(s,s+x)
        