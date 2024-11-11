N, K = map(int, input().split())
dp = [[[0]*N**2*2 for a in range(N+1)] for b in range(N+1)]

dp[0][0][0] = 1
for i in range(N):
    for j in range(N):
        for k in range(N**2):
            dp[i+1][j+1][k+2*j+2] += dp[i][j][k]
            dp[i+1][j][k+2*j] += dp[i][j][k] * (2*j+1)
            if j: dp[i+1][j-1][k+2*j-2] += dp[i][j][k] * j**2

print(dp[N][0][K] % (10**9+7))