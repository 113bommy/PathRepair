# -*- coding: utf-8 -*-
"""
Created on Sat Jun 20 12:09:44 2020

@author: user
"""

n=int(input())
l=list(map(int,input().split()))
a=list(set(l))
a.sort()
#print(a)
if(len(a)==3 and (a[2]+a[0])/2==a[1]):
    res='YES'
elif(len(a)<=2):
    res='YES'
else:
    res='NO'
print(res)