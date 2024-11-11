MOD = int(1e9 + 7)
N = int(1e5)
M = 13

s = input()
dp = [[0 for x in range(M)] for x in range(N+10)]
dp[0][0] = 1

for i in range(len(s)):
    for j in range(M):
        for k in range(10):
            if s[i] == "?" or s[i] == str(k):
                dp[i+1][(j*10 +k) % M] += dp[i][j]
                dp[i+1][(j*10 +k) % M] %= MOD


print(dp[len(s)][5])
