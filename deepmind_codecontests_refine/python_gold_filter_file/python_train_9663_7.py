s = input()
S = len(s)

#i文字目まで見たときj文字目まで確定しているときの組み合わせ
dp = [[0 for i in range(4)]for j in range(S+1)]
mod = 10**9+7

dp[0][0] = 1

for j in range(4):
    for i in range(S):
        dp[i+1][j] = dp[i][j]%mod
        if s[i] == "?":
            dp[i+1][j] = dp[i][j]*3%mod
            if j > 0:
                dp[i+1][j] += dp[i][j-1]%mod
        else:
            if "ABC".index(s[i])+1 == j:
                dp[i+1][j] += dp[i][j-1]%mod

print(dp[S][3]%mod)