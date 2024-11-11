N,M = map(int,input().split())
A = list(int(input()) for _ in [0]*M)
mod = 10**9 + 7
dp = [0]*(N+1)
dp[0] = 1
for i in range(1,N+1):
    dp[i] = (dp[i-1]+dp[i-2]) % mod
    if i in A:
        dp[i] = 0
print(dp[N])

