import itertools
N, M = [int(_) for _ in input().split()]
S = [int(_) for _ in input().split()]
T = [int(_) for _ in input().split()]
mod = 10**9 + 7
dp = [[1] * (M + 1)] + [[1] + [0] * M for _ in range(N)]
for n, m in itertools.product(range(N), range(M)):
    dp[n + 1][m + 1] = dp[n][m + 1] + dp[n + 1][m] - dp[n][m]
    if S[n] == T[m]:
        dp[n + 1][m + 1] += dp[n][m]
    dp[n + 1][m + 1] %= mod
print(dp[-1][-1])
