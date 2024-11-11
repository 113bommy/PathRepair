N = int(input())
*P, = map(float, input().split())
dp = [[0]*(N+1) for _ in range(N)]
dp[0][0] = 1 - P[0]; dp[0][1] = P[0]
for i in range(1, N):
    for j in range(i+2):
        dp[i][j] = dp[i-1][j] * (1 - P[i]) + dp[i-1][j-1] * P[i]
print(sum(dp[N-1][N//2 + 1:]))