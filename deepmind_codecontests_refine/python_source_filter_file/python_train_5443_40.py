# -*- coding: utf-8 -*-
"""
Created on Tue Oct 27 20:34:58 2020

@author: Dark Soul
"""
t=int(input(''))
for _ in range(t):
    [l,r]=list(map(int,input().split()))
    if l==r or l>1:
        print('YES')
    else:
        print('NO')