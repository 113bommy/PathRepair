N = int(input())
P = tuple(map(float, input().split()))

dp = [[0 for _ in range(N + 1)] for __ in range(N + 1)]
dp[0][0] = 1
for i in range(N):
    for j in range(N):
        dp[i + 1][j + 1] += dp[i][j] * P[i]
        dp[i + 1][j] += dp[i][j] * (1 - P[i])
print(sum(dp[N][(N + 1) // 2:]))
