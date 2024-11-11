#!/usr/bin/env python3
import sys, math, itertools, heapq, collections, bisect, string
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf')
mod = 10**9+7
ans = 0 ;count = 0 ;pro = 1



n=int(input())
A=list(map(int,input().split()))
L=[0]*n
R=[0]*n
for i in range(n-1):
    count+=1
    L[i]=count
    if A[i]>=A[i+1]:
        count=0
L[n-1]=count+1
count=0
for i in range(n-1,0,-1):
    count+=1
    R[i]=count
    if A[i-1]>A[i]:
        count=0
R[0]=count+1
# print(L)
# print(R)

if L[n-1]==R[0]==n:
    print(n)
    exit()

for i in range(1,n-1):
    if A[i-1]<A[i+1]:
        ans=max(ans,L[i-1]+R[i+1])
    else:
        ans=max(ans,L[i-1],R[i+1])
ans=max(ans,R[1])
ans=max(ans,L[n-2])
print(ans)
    