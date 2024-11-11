N, A = map(int, input().split())
x = [int(_) for _ in input().split()]
M = 2500
dp = [[[0]*(N+1) for _ in range(M+1)] for _ in range(N+1)]
dp[0][0][0] = 1

for i in range(1, N+1):
    for j in range(M+1):
        for k in range(i+1):
            dp[i][j][k] = dp[i-1][j][k]
            if j >= x[i-1] and k > 0:
                dp[i][j][k] += dp[i-1][j-x[i-1]][k-1]

ans = 0
for i in range(1, N+1):
    ans += dp[N][A*i][i]

print(ans)