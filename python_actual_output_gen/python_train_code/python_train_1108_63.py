# -*- coding: utf-8 -*-
"""
Created on Tue Mar 31 10:57:13 2020

@author: prana
"""

a,b=list(map(int,input().split()))
i=1
while b*(2**i)>a*(3**i):
    
        i+=1
print(i)
