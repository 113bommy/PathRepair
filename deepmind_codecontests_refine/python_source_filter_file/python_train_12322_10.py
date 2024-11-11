# -*- coding: utf-8 -*-
"""
Created on Tue Jul 14 01:53:47 2020

@author: Dell
"""
import math
n = int(input())
i=max(1,int(math.sqrt(n))-1)
while i*i<=n:
    if n%i==0:
        k=0
        z=i
        while z>0:
            k+=z%10
            z//=10
        if k+i==n//i:
            print(i)
            break
    i+=1
else:
    print(-1)
