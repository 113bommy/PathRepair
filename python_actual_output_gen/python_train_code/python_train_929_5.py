# -*- coding: utf-8 -*-
"""
Created on Mon Oct 26 21:22:22 2020

@author: Morris
"""

n,h=[int(x) for x in input().split()]
l=[int(x) for x in input().split()]
w=0
for i in l:
    if i<h:
        w+=1
    else:
        w+=2
print(w)