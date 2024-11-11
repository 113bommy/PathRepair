# -*- coding: utf-8 -*-
"""
Created on Tue Oct 13 13:58:28 2020

@author: 赵泽华
"""

n=input()
n=int(n)
for i in range(n):
    a=input()
    a=180-float(a)
    b=float(360/a)
    c=int(360/a)
    if b==c:
        print('YES')
    else:
        print('NO')