# -*- coding: utf-8 -*-
"""
Created on Fri Nov 30 08:28:03 2018

@author: jinbin
"""

input()
s=t=0;a=-1
for i in input().split():
    if a==-1 and int(i)>0:
        s=0
    s+=int(i)
    if s<0 and int(i)==-1:
        t+=1
    a=int(i)
print(t)