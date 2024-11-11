#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 14 13:35:44 2018

@author: abhinavvajpeyi)
"""
n=int(input())
a=[int(i) for i in input().strip().split(' ')]
for i in range(n):
    if a[i]%2==0:
        a[i]=a[i]-1
print(*a)

    
    
    


        