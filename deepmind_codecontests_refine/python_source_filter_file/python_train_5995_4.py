# -*- coding: utf-8 -*-
"""
Created on Tue Aug 25 02:16:02 2020

@author: Dark Soul
"""

[n,k,x]=list(map(int, input().split()))
arr=list(map(int, input().split()))
if k%2:
    y=1
else:
    y=2
if k<10:
    y=k
if k==0:
    print(max(arr),min(arr))
else:
    for j in range(y):
        arr.sort()
        for i in range(0,n,2):
            arr[i]=arr[i]^x
        
    
    print(max(arr),min(arr))
