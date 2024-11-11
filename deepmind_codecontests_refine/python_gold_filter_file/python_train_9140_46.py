# coding: utf-8
# Your code here!
n=int(input())
p = [float(i) for i in input().split()]

dp=[0]*(n+1)
dp[0]=1
for i in range(n):
    for j in range(n,-1,-1):
        dp[j] = dp[j]*(1-p[i]) + dp[j-1]*p[i]
#    print(dp)

print(sum(dp[(n+1)//2:]))        