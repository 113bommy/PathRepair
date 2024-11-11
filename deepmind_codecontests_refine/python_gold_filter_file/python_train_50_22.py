#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Nov  3 13:36:06 2020

@author: zuoxichen
"""
s1=input()
l1=s1.split()
n=int(l1[0])
m=int(l1[1])
i=0
l4=list()
while i<n:
    s2=input()
    l2=s2.split()
    l3=list(int(l) for l in l2)
    l3.pop(0)
    for k in l3:
        l4.append(k)
    i+=1
else:
    for i in range(1,m+1):
        if i not in l4:
            print('NO')
            break
    else:
        print('YES')