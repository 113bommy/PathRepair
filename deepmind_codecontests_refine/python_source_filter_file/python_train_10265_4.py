import sys
import math
import collections
import heapq
import decimal
input=sys.stdin.readline
n,m=(int(i) for i in input().split())
l=[]
for i in range(n):
    l.append(list(input()))
ind=[]
k=-1
for i in range(n):
    if(l[i].count('1')>0):
        k=i
        break
if(k==-1):
    print(0)
elif(k==n-1):
    k1=0
    for i in range(m+1,-1,-1):
        if(l[n-1][i]=='1'):
            k1=i
            break
    print(k1)
else:
    for i in range(n-1,k-1,-1):
        t=[-1,-1]
        for j in range(m+2):
            if(l[i][j]=='1'):
                t[0]=j
                break
        for j in range(m+1,-1,-1):
            if(l[i][j]=='1'):
                t[1]=j
                break
        ind.append(t)
    dp=[[0,0] for j in range(n-k)]
    dp[0][0]=2*ind[0][1]+1
    dp[0][1]=m+2
    for i in range(1,n-1-k):
        dp[i][0]=min(dp[i-1][0]+2*max(ind[i][1],0)+1,dp[i-1][1]+m+2)
        if(ind[i][0]==-1):
            dp[i][1]=min(dp[i-1][1]+1,dp[i-1][0]+m+2)
        else:
            dp[i][1]=min(dp[i-1][1]+2*(m+1-ind[i][0])+1,dp[i-1][0]+m+2)
    print(min(dp[n-2-k][0]+ind[n-1-k][1],dp[n-2-k][1]+m+1-ind[n-1-k][0]))