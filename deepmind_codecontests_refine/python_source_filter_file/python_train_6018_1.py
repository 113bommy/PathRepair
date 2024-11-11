mod = 10 ** 9 + 7
s = input()
n = len(s)
dp = [[0 for _ in range(13)] for _ in range(n + 1)]
dp[0][0]=1
for i in range(n):
    if s[i] == '?': 
        for j in range(10):
            for k in range(13):
                dp[i + 1][(k * 10 + j) % 13]+=dp[i][k] % mod
    else:
        for k in range(13): 
            dp[i + 1][(k * 10+ int(s[i])) % 13]+=dp[i][k] % mod
print(dp[-1][5] % mod)
