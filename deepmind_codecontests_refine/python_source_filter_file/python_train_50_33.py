# -*- coding: utf-8 -*-
"""
Created on Tue Nov 10 16:49:29 2020

@author: shevipher
"""

n,m=[int(x) for x in input().split()]
bulbs=[]

for i in range(2,n+1):
    bulb=[int(j) for j in input().split()]
    bulbs=bulbs+bulb[1:]
if len(set(bulbs)) ==m:
    print('YES')
else:
    print('NO')
    