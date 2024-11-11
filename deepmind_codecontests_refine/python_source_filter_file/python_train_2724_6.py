n1,n2,k1,k2 = map(int, input().split())
m = int(1e8)
dp = [[[0,0] for i in range(n2+1)] for j in range(n1+1)]
dp[0][0][0], dp[0][0][1] = 1,1
for i in range(0,n1+1):
    for j in range(0,n2+1):
        for k in range(1,min(i,k1)+1):
            dp[i][j][0] += dp[i-k][j][1]
        for k in range(1, min(j,k2)+1):
            dp[i][j][1] += dp[i][j-k][0]
        dp[i][j][0]%= m
        dp[i][j][1]%= m
#print(dp)
print(sum(dp[n1][n2]))
