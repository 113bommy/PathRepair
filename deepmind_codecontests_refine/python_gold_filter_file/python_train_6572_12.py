# -*- coding: utf-8 -*-
"""
Created on Thu Dec 20 14:16:30 2018
@author: usmon
"""
n = int(input()) 
a = []
for i in range(n):
    a.append(input())
    
if n<=2:
    print(0)
else:
    k=0
    for i in range(1,n-1):
        for j in range(1,n-1):
            if a[i][j]==a[i-1][j-1]==a[i-1][j+1]==a[i+1][j-1]==a[i+1][j+1]=="X":
                k+=1
    print(k)            