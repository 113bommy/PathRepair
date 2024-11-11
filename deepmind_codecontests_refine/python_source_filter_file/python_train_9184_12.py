import sys
import math
input=sys.stdin.readline
#t=int(input())
t=1
for _ in range(t):
    n,h,l,r=map(int,input().split())
    a=list(map(int,input().split()))
    a.insert(0,0)
    dp=[[0 for j in range(n+1)] for i in range(n+1)]
    pref=[0]*(n+2)
    for i in range(1,n+1):
        pref[i]=pref[i-1]+a[i]
    
    if a[1]>=l and a[1]<=r:    
        dp[1][0]=1
    
    if (a[1]-1)>=l and (a[1]-1)<=r:
        dp[1][1]=1
        
    for i in range(2,n+1):
        for j in range(i+1):
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])
            x=(pref[i]-j)%h       
            if x>=l and x<=r:
                dp[i][j]+=1
   
    maxi=0
    for j in range(n):
        maxi=max(dp[n][j],maxi)
    print(maxi)    