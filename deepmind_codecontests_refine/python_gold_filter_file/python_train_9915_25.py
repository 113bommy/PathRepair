# -*- coding: utf-8 -*-
"""
Created on Tue Oct  6 00:07:54 2020

@author: Dark Soul
"""

t=int(input(''))
for _ in range(t):
    [n,k]=list(map(int,input().split()))
    a=list(map(int,input().split()))
    dp=[0]*n
    for i in range(1,n-1):
        if a[i]>a[i-1] and a[i]>a[i+1]:
            dp[i]=1
    for i in range(1,n):
        dp[i]+=dp[i-1]
    mx=-1
    ind=0
    for i in range(n+1-k):
        asi=dp[i+k-1]
        if i:
            asi-=dp[i-1]
            if dp[i]>dp[i-1]:
                asi-=1
        if dp[i+k-1]>dp[i+k-2]:
            asi-=1
        if asi>mx:
            mx=asi
            ind=i+1
    print(mx+1,ind)
    