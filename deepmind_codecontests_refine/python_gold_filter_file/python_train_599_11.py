MOD = 998244353
n, s = map(int, input().split())
a = list(map(int, input().split()))
dp = [[0] * (s+1) for _ in range(n+1)]
dp[0][0] = 1

for i in range(n):
    for j in range(s+1):
        dp[i+1][j] += dp[i][j]
        nj = j + a[i]
        if nj > s: continue
        dp[i+1][nj] += i+1 if j == 0 else dp[i][j]
        if nj == s: dp[i+1][nj] *= n-i
        dp[i+1][nj] %= MOD

print(dp[n][s] % MOD)
