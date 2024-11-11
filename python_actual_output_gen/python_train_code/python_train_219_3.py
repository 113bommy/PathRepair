n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
dp = [[0] * (m+2) for _ in range(n+2)]
mod = 1000000007

for i in range(n):
    dp[i][0] = 1
for i in range(m):
    dp[0][i] = 1

for i in range(1, n+1):
    for j in range(1, m+1):
        dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % mod
        if s[i-1] == t[j-1]:
            dp[i][j] += dp[i-1][j-1]
            dp[i][j] %= mod
print(dp[n][m])
