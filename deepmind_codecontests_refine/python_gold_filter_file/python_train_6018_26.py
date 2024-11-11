s = input()
l = len(s)
MOD = 10**9+7
dp = [[0]*13 for _ in range(100005)]
dp[0][0] = 1
for i in range(l):

    c = -1 if s[i] == '?' else int(s[i])
    for j in range(10):
        if c != -1 and c != j:
            continue
        for r in range(13):
            dp[i+1][(10*r+j)%13] += dp[i][r]
    for k in range(13):
        dp[i+1][k] %= MOD
print(dp[l][5])