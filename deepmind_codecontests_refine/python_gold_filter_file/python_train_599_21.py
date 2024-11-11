n, s = map(int, input().split())
a = list(map(int, input().split()))

dp = [[0 for _ in range(s+1)] for _ in range(n+1)]
for i in range(n+1):
    dp[i][0] = i + 1
mod = 998244353

ans = 0
for i in range(n):
    for j in range(s+1):
        if s > j > 0:
            dp[i+1][j] += dp[i][j]
        if j + a[i] <= s:
            dp[i+1][j+a[i]] += dp[i][j]
            dp[i+1][j+a[i]] %= mod

    ans += dp[i+1][s] * (n - i)
    ans %= mod

print(ans)