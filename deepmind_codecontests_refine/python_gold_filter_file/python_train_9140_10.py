N = int(input())
P = [0]
P.extend(map(float, input().split()))

dp = [[0 for _ in range(N+1)] for _ in range(N+1)]
for i in range(N+1):
    dp[i][0] = 1

for i in range(1, N+1):
    for j in range(1, N+1):
        dp[i][j] = dp[i-1][j-1] * P[i] + dp[i-1][j] * (1-P[i])

print(dp[-1][N//2+1])
