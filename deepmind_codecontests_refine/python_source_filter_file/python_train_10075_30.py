MOD = 998244353
N,S = map(int,input().split())
A = list(map(int,input().split()))
dp = [[0]*(S+1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(N):
    for j in range(S+1):
        # dp[i+1][j] = dp[i][j]
        dp[i+1][j] = 2*dp[i][j]
        if j - A[i] >= 0:
            dp[i+1][j] += dp[i][j-A[i]]
        dp[i][j] %= MOD


print(dp[N][S])