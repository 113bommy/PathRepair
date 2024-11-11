# -*- coding: utf-8 -*-
"""
Created on Fri Oct 14 22:14:36 2016

@author: Arpan
"""
n,k=input().split()
n,k=int(n),int(k)
a=[0 for x in range(n)]
b=set()

for i in range(n):
    p,t=[int(x) for x in input().split()]
    te=100*p+50-t
    a[i]=te
    b.add(te)
a=sorted(a,reverse=True)
d={x:0 for x in b}
for i in a:
    d[i]+=1
#print (k,a,b,d)
je=a[k-1]
re=d[je]
print(re)