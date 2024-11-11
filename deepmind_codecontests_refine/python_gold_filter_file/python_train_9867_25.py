a,b,c,d = map(int,input().split())
ans = 0
dp = [[0]*(d+1) for i in range(c+1)]
mod = 998244353
dp[a][b] = 1
for i in range(a+1,c+1):
    dp[i][b] = dp[i-1][b] * b % mod
for i in range(b+1,d+1):
    dp[a][i] = dp[a][i-1] * a % mod
for i in range(a+1,c+1):
    for j in range(b+1,d+1):
        dp[i][j] = ((dp[i-1][j]*j) + (dp[i][j-1]*i) - (dp[i-1][j-1]*(i-1)*(j-1)))%mod
print(dp[c][d])