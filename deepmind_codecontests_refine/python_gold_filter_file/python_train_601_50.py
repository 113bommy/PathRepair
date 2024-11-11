N, M = map(int, input().split())
S = list(map(int, input().split()))
T = list(map(int, input().split()))
MOD = 10**9 + 7

dp = [[0] * (M + 1) for _ in range(N + 1)]  # dp[s][t]

for i, s in enumerate(S, start=1):
    for j, t in enumerate(T, start=1):
        v = dp[i - 1][j] + dp[i][j - 1]
        if s == t:
            v += 1
        else:
            v -= dp[i - 1][j - 1]
        dp[i][j] = v % MOD

print((dp[-1][-1] + 1) % MOD)
