#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar  5 21:06:40 2019

@author: adarsh
"""

c1=int(input())
c2=int(input())
c3=int(input())
c4=int(input())

if c1!=c4:
    print(0)
elif c3>0:
    if c1>0 and c4>0:
        print(1)
    else:
        print(0)
else:
    print(1)
    
