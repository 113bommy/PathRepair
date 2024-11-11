# -*- coding: utf-8 -*-
"""
Created on Sat Nov 23 18:29:41 2019

@author: 86138
"""

#200B Drinks
n = int(input())
p = [ float(x)/100 for x in input().split()]
l = 0
for i in range(n):
    if p[i] == 0:
        continue
    else:
        l = l + p[i]
    i +=1
l1 = l/n*100
print(l1)
