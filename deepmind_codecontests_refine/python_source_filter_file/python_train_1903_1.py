# -*- coding: utf-8 -*-
"""
Created on Tue Sep 15 17:39:13 2020

@author: mohit
"""

t=int(input())
for i in range(t):
    N=int(input())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    C=[]
    for j in range(len(A)):
        if(B[j]==0):
            C.append(A[j])
    C.sort(reverse=True)
    d=0
    for k in range(len(A)):
        if(B[k]==0):
            A[k]=C[d]
            d+=1
    A=list(map(str,A))
    print("".join(A))
