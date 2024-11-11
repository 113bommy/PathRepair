N, A = map(int, input().split())
x = list(map(int, input().split()))

dp = [[[0] * 2550 for i in range(55)] for i in range(55)]

dp[0][0][0] = 1
for i in range(N):
    for j in range(N):
        for k in range(2451):
            dp[i+1][j+1][k+x[i]] += dp[i][j][k]
            dp[i+1][j][k] += dp[i][j][k]

ans = 0
for i in range(1, N+1):
    ans += dp[N][i][A*i]

print(ans)