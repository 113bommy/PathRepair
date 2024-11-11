N,A = map(int,input().split())
X = list(map(int,input().split()))

dp = [[[0 for k in range(2501)] for j in range(N+1)] for i in range(N+1)]

for i in range(1,N+1):
    x = X[i-1]
    dp[i][1][x] += 1
    for j in range(1,i+1):
        for k in range(1,2501):
            if k-x > 0:
                dp[i][j][k] += dp[i-1][j-1][k-x] + dp[i-1][j][k]
            else:
                dp[i][j][k] += dp[i-1][j][k]

ans = 0

for j in range(1,N+1):
    ans += dp[N][j][j*A]
print(ans)
