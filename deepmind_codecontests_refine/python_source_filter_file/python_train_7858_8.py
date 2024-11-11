# -*- coding: utf-8 -*-
"""
Created on Sat Oct 10 09:17:47 2020

@author: feibiaodi
"""

n=int(input())
list1=[int(x) for x in input().split()]
c=1
d=[]
for i in range(0,n-1):
    if list1[i]<=list1[i+1]:
        c=c+1
    if list1[i]>list1[i+1] or i==n-2:
        d.append(c)
        c=1
if len(d)==1:
    print(d[0])
if len(d)==0:
    print(0)
if len(d)!=1 and len(d)!=0:
    print(max(d))