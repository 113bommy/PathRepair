# -*- coding: utf-8 -*-
"""
Created on Tue Feb  4 16:43:58 2020

@author: DeLL
"""

n=int(input())
a1,a2=[float(x) for x in input().split()]
L=set()
Li=set()

i=a1+0.5
while(i<=a2):
    L.add(i)
    i+=1

print(L)   

for j in range(n-1):
    a,b=[float(x) for x in input().split()]
    L1=set()
    i=a
    while(i<=b):
        L1.add(i)
        i+=0.5
    print(L)    
    print(L1)
    L=L.difference(L1)
    print(L)
print(len(L))