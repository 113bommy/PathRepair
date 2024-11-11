A, B, C, D = map(int, input().split())
MOD = 998244353
dp = [[0]*(D+1) for i in range(C+1)]
for i in range(A, C+1):
    for j in range(B, D+1):
        if (i, j) == (A, B):
            dp[i][j] = 1
        else:
            dp[i][j] = (dp[i-1][j]*j + dp[i][j-1]*i - dp[i-1][j-1]*(i-1)*(j-1)) % MOD

print(dp[-1][-1])