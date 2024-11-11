# -*- coding: utf-8 -*-
"""
Created on Wed Nov  4 08:21:46 2020

@author: feibiaodi
"""

n,m=map(int,input().split())
list1=[0]+[int(x) for x in input().split()]+[m]
a=b=c=0
for i in range(1,len(list1),2):
    a=a+list1[i]-list1[i-1]
b=a
for i in range(2,len(list1),2):
    c=c+list1[i-1]-list1[i-2]
    if list1[i]>list1[i-1]+1:
        d=a-c
        b=max(b,c+m-list1[i-1]-1-d)
print(b)
