mod = 998244353

N, S, *A = map(int, open(0).read().split())

dp = [[0] * (S + 1) for _ in range(N + 1)]
dp[0][0] = 1

for i, a in enumerate(A, 1):
    for j in range(S + 1):
        dp[i][j] = 2 * dp[i - 1][j] + (dp[i - 1][j - a] if j >= a else 0)

print(dp[N][S])