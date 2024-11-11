# -*- coding: utf-8 -*-
"""
Created on Thu Jul 23 05:12:27 2020

@author: Dark Soul
"""

t=int(input(''))
mat=[]
for i in range(t):
     mat.append(list(map(int, input().split())))
for i in range(t):
    n=mat[i][0]
    k=mat[i][1]
    a=int(n/k)
    if n%k==0:
        print(n)
    else:
        ex=n-a
        if ex>=int(k/2):
            print(k*a+int(k/2))
        else:
            print(k*a+ex)