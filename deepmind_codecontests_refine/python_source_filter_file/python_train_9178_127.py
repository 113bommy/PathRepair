# -*- coding: utf-8 -*-
"""
Created on Mon Aug  5 21:54:01 2019

@author: Sumeet Sagar Lenka
"""
import math
H,L=(input().split())
H=int(H)
L=int(L)
x=float((L**2+H**2)/2*H)
print(x-H)