mod = 10**9+7
N,K = map(int,input().split())
M = int(N**0.5)
dp = [[0]*M for _ in range(K+1)]
dp1 = [[0]*M for _ in range(K+1)]
dp2 = [[0]*M for _ in range(K+1)]

dp[0][0] = 1
dp1[0][0] = 1
dp2[0][0] = N
for m in range(1,M):
    dp[0][m] = 1
    dp1[0][m] = dp1[0][m-1]+dp[0][m]
    dp2[0][m] += dp2[0][m-1]+N//(m+1)*dp[0][m]

dp[1][0] = N
dp1[1][0] = N
dp2[1][0] = N**2
for m in range(1,M):
    dp[1][m] = N//(m+1)
    dp1[1][m] = dp1[1][m-1]+dp[1][m]
    dp2[1][m] += dp2[1][m-1]+N//(m+1)*dp[1][m]


for k in range(1,K):
    for m in range(M):
        dp[k+1][m] = dp1[k][M-1]+N//(m+1)*dp1[k-1][m]+dp2[k-1][M-1]-dp2[k-1][m]-M*dp1[k-1][M-1]
        dp[k+1][m] %= mod
        dp1[k+1][m] = dp1[k+1][m-1]+dp[k+1][m]
        dp1[k+1][m] %= mod
        dp2[k+1][m] = dp2[k+1][m-1]+N//(m+1)*dp[k+1][m]
        dp2[k+1][m] %= mod

print(dp[K][0])
