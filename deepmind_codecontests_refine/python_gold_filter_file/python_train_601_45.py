N, M = map(int, input().split())
S = list(map(int, input().split()))
T = list(map(int, input().split()))
MOD = 10**9 + 7

dp = [[0] * (M + 1) for _ in range(N + 1)]

for i, s in enumerate(S, start=1):
    for j, t in enumerate(T, start=1):
        if s == t:
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + 1) % MOD
        else:
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % MOD

print((dp[N][M] + 1) % MOD)
