n,t = map(int,input().split())
ab = [list(map(int, input().split())) for i in range(n)]

dp = [[0 for i in range(t+1)]for j in range(n+1)]

for i in range(n):
    ti,vi = ab[i]
    for j in range(t+1):
        if j + ti <= t:
            dp[i+1][j+ti] = max(dp[i+1][j+ti],dp[i][j]+vi)
        dp[i+1][j] = max(dp[i][j],dp[i+1][j])

ma = 0
for i,(ti,vi) in enumerate(ab):
    ma = max(ma,dp[i][t-1]+vi)
print(ma)