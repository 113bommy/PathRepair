mod = 10**9 + 7
n, t = map(int, input().split())
dp = [[0 for i in range(2016)] for j in range(2016)]
dp[0][1] = 1
for i in range(1, t+1):
    for j in range(1, n+1):
        for k in range(j, n+1, j):
            dp[i][k] += dp[i-1][j]
            dp[i][k] %= mod
ans = 0
for i in range(1, n+1):
    ans += (dp[t][i])%mod
print(ans)