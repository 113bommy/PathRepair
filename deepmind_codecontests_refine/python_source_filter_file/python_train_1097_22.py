# -*- coding: utf-8 -*-
"""
Created on Sun Dec 27 15:59:07 2020

@author: dell
"""
a=int(input())
lst=[]
for i in range(a):
    lst.append(0)
    inp=input()
    inp=inp.split()
    for j in range(3):
        inp[j]=float(inp[j])
    lst[i]=inp
    
x=0
y=0
z=0

for i in range(len(lst)):
    x+=lst[i][0]
    y+=lst[i][1]
    z+=lst[i][2]
if x==0 and y==0 and z==0:
    print('Yes')
else:
    print('No')