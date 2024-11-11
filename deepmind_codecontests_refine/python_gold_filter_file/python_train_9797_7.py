# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import math

s=input()
x=s.split()
n=int(x[0])
k=int(x[1])
if n%(2*k+1)==0:
    print(n//(2*k+1))
    for i in range(k+1,n+1,2*k+1):
        print(i, end=" ")
elif n%(2*k+1)>=k+1:
    print(n//(2*k+1)+1)
    for i in range(k+1,n+1,2*k+1):
        print(i, end=" ")
else:
    print(n//(2*k+1)+1)
    for i in range(k+1,n+1,2*k+1):
        print(i-(k+1-n%(2*k+1)), end=" ")
    print(n)
        
    