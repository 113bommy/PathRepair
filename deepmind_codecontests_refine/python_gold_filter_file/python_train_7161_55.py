n, t = map(int, input().split())
ab = [tuple(map(int, input().split())) for i in range(n)]

ab.sort()

dp = [[0] * t for i in range(n+1)]
ans = 0
for i in range(n):
    for j in range(t):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j])
        if j - ab[i][0] >= 0:
            dp[i+1][j] = max(dp[i+1][j], dp[i][j - ab[i][0]] + ab[i][1])
    now = dp[i][t-1] + ab[i][1]
    ans = max(ans, now)

print(ans)