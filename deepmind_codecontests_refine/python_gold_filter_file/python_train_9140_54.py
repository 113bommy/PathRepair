N = int(input())
P = list(map(float, input().split()))

dp = [[1] + [0]*N for i in range(N+1)]
for i in range(1, N+1):
  for j in range(1, i+1):
    dp[i][j] = dp[i-1][j-1]*(P[i-1]) + dp[i-1][j]*(1-P[i-1])

print(dp[-1][(N+1)//2])