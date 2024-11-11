N = int(input())
p = list(map(float, input().split()))

dp = [[0.] * (N+1) for _ in range(N+1)]
dp[0][0] = 1.

for i in range(1, N+1):
    for j in range(i+1):
        prob = dp[i-1][j-1]*p[i-1]
        if i > 0:
            prob += dp[i-1][j]*(1.-p[i-1])
        dp[i][j] = max(dp[i][j], prob)
print(sum(dp[-1][N//2+1:]))