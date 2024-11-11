mod = 10 ** 9 + 7

N, M = map(int, input().split())
S = input().split()
T = input().split()

dp = [[0] * (M + 1) for _ in range(N + 1)]
dp[0][0] = 1

for i in range(N + 1):
    for j in range(M + 1):
        if 1 <= i and 1 <= j and S[i - 1] == T[j - 1]:
            dp[i][j] += dp[i - 1][j - 1]
        if 1 <= i:
            dp[i][j] += dp[i - 1][j]
        if 1 <= j:
            dp[i][j] += dp[i][j - 1]
        if 1 <= i and 1 <= j:
            dp[i][j] -= dp[i - 1][j - 1]
        dp[i][j] %= mod

print(dp[N][M])
