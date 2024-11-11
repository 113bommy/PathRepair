def solve():
    MOD = 998244353

    A, B, C, D = map(int, input().split())

    dp = [[0]*(D+1) for _ in range(C+1)]
    dp[A][B] = 1
    for j in range(B+1, D+1):
        dp[A][j] = dp[A][j-1] * A % MOD
    for i in range(A+1, C+1):
        dp[i][B] = dp[i-1][B] * B % MOD

    for i in range(A+1, C+1):
        for j in range(B+1, D+1):
            dp[i][j] = (dp[i-1][j]*j + dp[i][j-1]*i - dp[i-1][j-1]*(i-1)*(j-1)) % MOD

    print(dp[C][D])


solve()
