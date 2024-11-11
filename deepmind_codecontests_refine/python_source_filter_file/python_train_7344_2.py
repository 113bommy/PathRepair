# -*- coding: utf-8 -*-
"""
Created on Sat Jan 12 22:39:41 2019

@author: Noussa
"""

n,b,d = map(int,input().split())
a = list(map(int,input().split()))

empties = 0
waste = 0 
for e in a:
    if e > b:
        continue
    waste += e
    if waste > b:
        empties += 1
        waste = 0
    
print(empties)
