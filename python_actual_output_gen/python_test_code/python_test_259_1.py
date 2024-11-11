n,m,k = list(map(int,input().split()))
a = list(map(int,input().split()))
dp = [[float('-inf')]*m for i in range(n)]
dp[0][0] = a[0]
for i in range(1,n):
    for j in range(1,m):
        dp[i][j] = dp[i-1][j-1] + a[i]
    dp[i][0] = max(dp[i-1][m-1]-k, 0)+a[i]
        #if dp[i-1][j] != float()
print(max(max([max(x) for x in dp]),0))    