N = int(input())
P = list(map(float, input().split()))

dp = [[0] * (N + 1) for _ in range(N + 1)]
dp[0][0] = 1

for i in range(N):
    p = P[i]
    q = 1 - p
    dp[i + 1][0] = dp[i][0] * q
    for j in range(1, i + 2):
        dp[i + 1][j] = dp[i][j - 1] * p + dp[i][j] * q

print (sum(dp[N][(N + 1) // 2:]))