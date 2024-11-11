N = int(input())
P = [float(i) for i in input().split()]

dp = [[0.0] * (N + 1) for _ in range(N + 1)]
dp[0][0] = 1.0

for i, p in enumerate(P, 1):
    for j in range(N + 1):
        dp[i][j] = p * dp[i - 1][j - 1] + (1 - p) * dp[i - 1][j]

print(sum(dp[N][-(-N // 2):]))