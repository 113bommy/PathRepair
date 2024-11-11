n = int(input())
p = list(map(float, input().split()))
    
dp = [[0]*(n+1) for _ in range(n+1)]
dp[0][0] = 1

for i in range(0, n):
    for j in range(0, i+1):
        dp[i+1][j+1] = dp[i][j]*p[i]
        dp[i+1][j] = dp[i][j]*(1-p[i]) + dp[i][j-1]*p[i]
        
ans = sum([dp[n][i] for i in range(n//2+1,n+1)])
print(ans)