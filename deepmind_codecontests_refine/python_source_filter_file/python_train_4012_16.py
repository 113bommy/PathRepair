a, b = (int(x) for x in input().split())
dp = [[0 for c in range(200)] for r in range(200)]
dp[1][1] = 1
dp[2][1] = 1
dp[2][2] = 1
dp[1][2] = 1
dp[1][3] = 2
dp[3][1] = 2
for sm in range(5,200):
    dp[1][sm-1] = dp[2][sm-3] + 1
    for i in range(2,sm-1):
        dp[i][sm-i] = max(dp[i-2][sm-i+1], dp[i+1][sm-i-2]) + 1
    dp[sm-1][1] = dp[sm-3][2] + 1
print (dp[a][b])
