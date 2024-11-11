import math

n=int(input())
a=list(map(int,input().split()))
s=[input() for _ in range(n)]
dp=[[0]*2 for _ in range(n)]

dp[0]=[0,a[0]]
for i in range(1,n):
    dp[i]=[math.inf]*2

    if s[i-1]<=s[i]:
        dp[i][0]=min(dp[i-1][0],dp[i][0])
    if s[i-1][::-1]<=s[i]:
        dp[i][0]=min(dp[i-1][1],dp[i][0])
    if s[i-1]<=s[i][::-1]:
        dp[i][1]=min(dp[i-1][0]+a[i],dp[i][1])
    if s[i-1][::-1]<=s[i][::-1]:
        dp[i][1]=min(dp[i-1][1]+a[i],dp[i][1])

res=min(dp[-1])
print(-1 if res==math.inf else res)