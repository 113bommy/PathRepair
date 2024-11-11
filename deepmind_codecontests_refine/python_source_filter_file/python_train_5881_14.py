# -*- coding: utf-8 -*-
"""
Created on Thu Oct 25 11:10:04 2018

@author: Quaint Sun
"""



n=int(input())
original=list(int(i) for i in input())
unlock=list(int(i) for i in input())

step=0
for i in range(5):
    dif=max(original[i],unlock[i])-min(original[i],unlock[i])
    if dif>5:
        step=step+10-dif
    else:
        step=step+dif
    
print(step)














