mod = 10 ** 9 + 7

N, M = map(int, input().split())
S = input().split()
T = input().split()

dp = [[0] * (M + 2) for _ in range(N + 2)]
for i in range(N+1):
    dp[i][0] = 1
for j in range(M+1):
    dp[0][j] = 1

for i, s in enumerate(S, 1):
    for j, t in enumerate(T, 1):
        dp[i][j] += dp[i - 1][j]
        dp[i][j] += dp[i][j - 1]
        if s == t:
            dp[i][j] += dp[i - 1][j - 1]
        dp[i][j] -= dp[i - 1][j - 1]
        dp[i][j] += mod
        dp[i][j] %= mod

print(dp[N][M])