n = int(input())
p = list(map(float, input().split()))

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
dp[0][0] = 1
for i in range(n):
    dp[i+1][0] = dp[i][0] * (1-p[i])
    for j in range(1, i+2):
        dp[i+1][j] = dp[i][j] * (1-p[i]) + dp[i][j-1] * p[i]

print(sum(dp[n][n // 2 + 1:]))
