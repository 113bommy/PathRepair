#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr  2 04:05:29 2020

@author: maruf
"""

n,m=map(int, input().split())
i=0
j=0
a=0
b=0
#while(i<n):
#    while(j<m):
for i in range(n):
    for j in range(m):
        if((i**2)+j==n and i+(j**2)==m):
            a+=1
           # b+=1
#    j+=1
#i+=1        
            
print(a)