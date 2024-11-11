N = int(input())

p = list(map(float, input().split()))

dp = [[0 for j in range(N+2)] for i in range(N+1)]
dp[0][1] = 1

for i in range(N):
    for j in range(i+2):
        dp[i+1][j+1] = dp[i][j+1] * (1 - p[i]) + dp[i][j] * p[i]

print(sum(dp[N][N + N//-2 + 2:]))
