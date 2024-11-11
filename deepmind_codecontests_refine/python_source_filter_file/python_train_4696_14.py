# -*- coding: utf-8 -*-
"""
Created on Sun Dec 23 14:56:55 2018

@author: QuocBinh
"""
import math

a,b,x,y=map(int,input().split())
t=math.gcd(x,y)
x=x//t
y=y//t
print(min(x,y))