N, *A = map(int, open(0).read().split())

A = sorted(enumerate(A), reverse=True, key=lambda x: x[1])

dp = [[0] * (N + 1) for _ in range(N + 1)]
for i, (p, a) in enumerate(A):
    for j in range(i + 1):
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a * (p - j))
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a * (N - (i - j) - 1 - p))

print(max(dp[N]))