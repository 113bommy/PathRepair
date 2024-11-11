#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr  9 19:01:42 2019

@author: jcharnay1
"""

n,k = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]

modulo = []
for i in range(k):
    modulo.append(0)
    
for cadeau in d:
    modulo[cadeau%k] += 1
    
res = 0
res += modulo[0]//2
for i in range(1,k):
    if i != k-i:
        res += min(modulo[i],modulo[k-i])
    else:
        res += modulo[i]//2

print(2*res)