# coding: utf-8
# Your code here!
N=int(input())
P=list(map(float,input().split()))

dp=[[0]*(N+1) for i in range(N+1)]

dp[0][0]=1
for n in range(N):
    for i in range(n+1):
        j=n-i
        dp[j][i+1]+=dp[j][i]*P[n]
        dp[j+1][i]+=dp[j][i]*(1-P[n])

ans=0
for i in range((N+1)//2):
    ans+=dp[i][-i-1]

print(ans)
