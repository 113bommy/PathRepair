n,m = map(int,input().split())
s = list(map(int,input().split()))
t = list(map(int,input().split()))
dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
for i in range(n+1):
    dp[i][0] = 1
for j in range(m+1):
    dp[0][j] = 1
mod = 10**9 + 7
for i in range(n):
    for j in range(m):
        if s[i] == t[j]:
            dp[i+1][j+1] = (dp[i][j+1]+dp[i+1][j])%mod
        else:
            dp[i + 1][j + 1] = (dp[i][j+1] + dp[i+1][j] - dp[i][j]+mod) % mod
print(dp[n][m])