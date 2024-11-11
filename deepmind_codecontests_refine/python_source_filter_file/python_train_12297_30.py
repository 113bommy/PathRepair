# -*- coding: utf-8 -*-
"""
Created on Sat Nov 24 13:37:27 2018

@author: japesh
"""
import math as m

t= int(input())
for _ in range(t):
    l,r=map(int,input().split())
    if l%2==1:
        if r%2==1:
            k=r
        else:
            k=0
            
        ans=int((r-l)/2)-k
    else:
        if r%2==0:
            k=r
        else:
            k=0
            
        ans=-m.ceil((r-l)/2)+k
    print(ans)