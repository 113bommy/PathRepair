# -*- coding: utf-8 -*-
"""
Created on Mon Nov 25 22:55:59 2019

@author: sihan
"""

i=input()
k=input()
t=len(i)
for j in range(t):
    if i[j]!=k[-(j+1)]:
        print('NO')
        t=0
        break
if t!=0:
    print('YES')