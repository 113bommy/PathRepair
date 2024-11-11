mod = 10**9+7

n,m = map(int,input().split())

s = list(map(int,input().split()))

s.sort()

s = [None] + s

dp = [[0 for i in range(m+1)] for j in range(n+1)]
dp[1] = [i % s[1] for i in range(m+1)]

for i in range(2,n+1):
    for j in range(m+1):
        dp[i][j] = (dp[i-1][j] * (i-1) + dp[n-1][j%s[i]]) % mod
print(dp[n][m])