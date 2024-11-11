s = input()

mod = 10**9+7
n = len(s)
dp = [[0]*13 for _ in range(n+1)]
dp[0][0] = 1
for i in range(n):
    if s[i] == '?':
        for j in range(10):
            for k in range(13):
                dp[i+1][(k*10+j)%13] += dp[i][k]
    else:
        for k in range(13):
            dp[i+1][(k*10+int(s[i]))%13] += dp[i][k]
    for k in range(13):
        dp[i+1][k] %= mod
print(dp[n][5])
