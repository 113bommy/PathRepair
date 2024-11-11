import math
n, k = map(int, input().split())
dp = [[0]*(n+1) for _ in range(k+1)]
dp[0][1] = 1
for i in range(1, k+1):
    for j in range(1, n+1):
        for m in range(j, n+1, j):
            dp[i][m] = (dp[i][m] + dp[i-1][j])%1000000007
ans = 0
for i in range(1, n+1):
    ans = (ans+dp[k][i])%1000000007
print(ans)
