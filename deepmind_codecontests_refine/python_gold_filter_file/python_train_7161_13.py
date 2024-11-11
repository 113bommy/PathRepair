n,t = map(int,input().split())
dp = [[0]*(t) for i in range(n+1)]
ab = [list(map(int,input().split()))for i in range(n)]
ab.sort()
ans = 0
for i in range(n):
    a = ab[i][0]
    b = ab[i][1]
    for j in range(t):
        dp[i+1][j] = max(dp[i+1][j],dp[i][j])
        if j- a >= 0:dp[i+1][j] = max(dp[i+1][j],dp[i][j-a]+b)
    ans = max(ans,dp[i][t-1]+b)

print(ans)
        
        