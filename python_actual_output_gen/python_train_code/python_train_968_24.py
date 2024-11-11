# -*- coding: utf-8 -*-
"""
Created on Thu Nov 12 17:18:59 2020

@author: user
Link:https://codeforces.com/problemset/problem/822/A
"""

a,b=map(int,input().split(" "))
c= min(a,b)
d= min(a,b)
# e=[]
for i in range(0,c-1):
    d = d*(c-i)

print(d)