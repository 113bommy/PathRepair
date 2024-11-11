# -*- coding: utf-8 -*-
"""
Created on Thu Oct 11 17:08:43 2018

@author: Quaint Sun
"""

stops=int(input())

t=0
num=0
nummax=0
while t<stops:
    a,b=map(int,input().split())
    num=num+(b-a)
    if num>nummax:
        nummax=num
    t=t+1
print(nummax)
    
    


















