MOD = 10**9 + 7
S = int(input())
dp = [0]*(S+4)
dp[0] = 1
dp[3] = 1
for i in range(4,S+1):
    for k in range(i-2):
        dp[i] += dp[k]
print(dp[S]%MOD)