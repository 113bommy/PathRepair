# -*- coding: utf-8 -*-
"""
Created on Mon Sep 28 13:13:06 2020

@author: feibiaodi
"""

a=int(input())
c=0
list1=[int(x) for x in input().split()]
for i in range (0,a):
    if list1[1]==1:
        c=c+1
        break
if c==0:
    print("EASY")
else:
    print("HARD")