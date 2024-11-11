S = input()

l = len(S)
MOD = 10**9+7
dp = [[0 for i in range(13)] for j in range(l+1)]
dp[0][0] = 1
for i in range(l):
    if S[i] == '?':
        for j in range(10):
            for k in range(13):
                dp[i+1][(k*10+j)%13] += dp[i][k] % MOD
    else:
        for k in range(13):
            dp[i+1][(k*10+int(S[i]))%13] += dp[i][k] % MOD

print(dp[-1][5] % MOD)