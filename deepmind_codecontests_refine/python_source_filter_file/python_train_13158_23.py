import sys,math as mt
import heapq as hp
import collections as cc
import math as mt
import itertools as it
input=sys.stdin.readline
sys.setrecursionlimit(8*10**5)
I=lambda:list(map(int,input().split()))
n,k=I()
l=I()
s=sum(l[:k])
dp=[0]*k+[s]
for i in range(k,n):
	s-=l[i-k]
	s+=l[i]
	dp.append(s)
mx=[[0,0]]*len(dp)
for i in range(k,len(dp)):
	if dp[i]>mx[i-1][0]:
		mx[i]=[dp[i],i]
	else:
		mx[i]=list(mx[i-1])
a=b=0
ans=0
for i in range(k,len(dp)):
	pp=dp[i]+mx[i-k][0]
	if pp>ans:
		ans=pp
		a=mx[i-k][1]-k+1
		b=i-k+1
print(ans,a,b)