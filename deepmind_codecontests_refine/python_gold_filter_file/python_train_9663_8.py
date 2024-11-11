S = str(input())
mod = 10 ** 9 + 7
L = len(S)
d = "ABC".index
dp = [[0 for _ in range(4)] for _ in range(L+1)]
dp[0][0] = 1
for i in range(len(S)):
    if S[i] == '?':
        dp[i+1][0] = dp[i][0] * 3
        dp[i+1][1] = dp[i][1] * 3 + dp[i][0]
        dp[i+1][2] = dp[i][2] * 3 + dp[i][1]
        dp[i+1][3] = dp[i][3] * 3 + dp[i][2]
        for j in range(4):
            dp[i+1][j] %= mod
    else:
        dp[i+1] = dp[i]
        j = d(S[i])
        dp[i+1][j+1] += dp[i][j] % mod

print(dp[-1][-1]%mod)