n,m,k = map(int, input().split())
dp = [[0 for _ in range(k+1)] for _ in range(n)]
for i in range(n):
    dp[i][0] = m
for i in range(1,n):
    for j in range(1,k+1):
        dp[i][j] = (m-1)*dp[i-1][j-1] + dp[i-1][j]
        dp[i][j] %= 998244354
#print(dp)
print(dp[n-1][k])
