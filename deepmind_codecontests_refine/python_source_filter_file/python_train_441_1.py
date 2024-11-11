# -*- coding: utf-8 -*-
"""
Created on Wed Sep 30 20:34:22 2020

@author: Dark Soul
"""

t=int(input(''))
for i in range(t):
    n=int(input(''))
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    sol=[0]*n
    sol[0]=a[0]
    for i in range(1,n):
        if a[i]!=sol[i-1]:
            sol[i]=a[i]
        elif b[i]!=sol[i-1]:
            sol[i]=b[i-1]
        else:
            sol[i]=c[i-1]
    if sol[0]==sol[n-1]:
        if a[i]!=sol[0] and a[i]!=sol[n-2]:
            sol[i]=a[i]
        elif b[i]!=sol[0] and b[i]!=sol[n-2]:
            sol[i]=b[i]
        else:
            sol[i]=c[i]
    print(*sol)
