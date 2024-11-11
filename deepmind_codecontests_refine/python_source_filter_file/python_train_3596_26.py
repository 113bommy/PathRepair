# -*- coding: utf-8 -*-
"""
Created on Wed Jul 29 21:36:45 2020

@author: DELL
"""
n,x=map(int,input().split())
c=0
for i in range(n):
    a,d=list(input().split())
    d=int(d)
    if a=='+':
        x+=int(d)
    else:
        if x>d:
            x-=d
        else:
            c+=1
print(x,c)
