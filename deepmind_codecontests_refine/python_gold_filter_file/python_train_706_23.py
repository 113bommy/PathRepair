n, k = map(int, input().split())
a = list(map(int, input().split()))

mod = 10**9 + 7
dp = [[0] * (k+1) for _ in range(n+1)]

dp[0][0] = 1
for i in range(1, n+1):
    cum = [0] * (k+2)
    for j in range(k+1):
        cum[j+1] = (cum[j] + dp[i-1][j]) % mod
        dp[i][j] += cum[j+1] - cum[max(0, j-a[i-1])]
        dp[i][j] %= mod

print(dp[n][k])