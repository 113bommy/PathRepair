# -*- coding: utf-8 -*-
"""
Created on Tue May 19 15:44:40 2020

@author: dell
"""
import math
n,k=map(int,input().split())
l=[]
for i in range(n):
    l.append(int(input()))
p=math.ceil(n/2)
q=p 
m=set(l)
t=0
for i in m:
    c=l.count(i)
    if p>0:
        p=p-c//2
     
if p==0:
    print(n)
else:
    t=2*(q-p)+p
print(t)

    
    
    


