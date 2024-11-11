nn=int(input())
import sys
input=sys.stdin.readline
cc=[int(input()) for _ in range(n)]
c=[cc[0]]
for i in range(1,nn):
    if cc[i]!=c[-1]:
        c.append(cc[i])
n=len(c)
mod=10**9+7
dp=[0]*(n+1)
sm=[0]*(max(c)+1)
dp[0]=1
for i in range(n):
    x=c[i]
    dp[i+1]+=sm[x]+dp[i]
    sm[x]+=dp[i]
    dp[i]%=mod
    dp[i+1]%=mod
print(dp[n])
