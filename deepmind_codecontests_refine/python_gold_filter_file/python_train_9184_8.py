def flag(x, l, r):
    return 1 if l <= x and x <= r else 0


I = lambda: list(map(int, input().split()))
n, h, l, r = I()
ls = I()
dp = [[-1e9 for j in range(n + 1)] for i in range(n + 1)]
dp[0][0] = 0
s = 0
for i in range(n):
    s += ls[i]
    for j in range(n+1):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + flag((s - j) % h, l, r))
        if j < n:
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + flag((s - j - 1) % h, l, r))
print(max(dp[n]))
