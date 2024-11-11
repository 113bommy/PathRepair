MOD = 10**9+7
s = input()
sl = list(s)
n=len(s)
dsl={i:sl[i] for i in range(n)}

dp={i:[0]*13 for i in range(n+1)}

dp[0][0]=1
for i in range(n):
    for k in range(10):
        if dsl[i] != "?" and dsl[i] != str(k):
            continue
        for j in range(13):
            dp[i+1][(j*10+k)%13] += dp[i][j]%MOD

print(dp[n][5]%MOD)
