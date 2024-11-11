n,m = map(int,input().split())
A = [int(input()) for _ in range(m)]
mod = 1000000007
dp = [0]*(n+1)
dp[0] = 1
for i in range(1,n+1):
    dp[i] = (dp[i-1] + dp[i-2])%mod
    if i in A:dp[i] = 0
print(dp[n])
