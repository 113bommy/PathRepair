# -*- coding: utf-8 -*-
"""
Created on Thu Oct 22 07:55:47 2020

@author: feibiaodi
"""

t=int(input())
list1=[int(x) for x in input().split()]
list2=sorted(list1)
c=list2.count(1)
d=list2.count(2)
e=list2.count(3)
g=[]
h=[]
j=[]
f=min(c,d,e)
print(f)
if f>0:
    for i in range(0,t):
        if list1[i]==1:
            g.append(i)
        if list1[i]==2:
            h.append(i)
        if list1[i]==3:
            j.append(i)
for k in range(0,f):
    print(str(g[k]),str(h[k]),str(j[k]))