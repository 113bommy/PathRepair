# -*- coding: utf-8 -*-
"""
Created on Tue Sep 22 19:18:30 2020

@author: Dark Soul
"""

n=int(input(''))
arr=list(map(int,input().split()))
arr.sort()
sol=[]
for i in range(n):
    sol.append([0,arr[i]])
for i in range(n):
    cnt=0
    while arr[i]%3==0:
        cnt+=1
        arr[i]/=3
    sol[i][0]=cnt
sol=sorted(sol,key=lambda x:x[0],reverse=True)
ans=[]
for i in range(n):
    ans.append(sol[i][1])
print(*ans)