s = input()
n = len(s)
mod = 10**9+7
dp = [[0]*13 for _ in range(n+1)]
dp[0][0] = 1
for i,d in enumerate(s):
	if d=="?":
		for x in range(10):
			for y in range(13):
				dp[i+1][(y*10+x)%13] += dp[i][y]
	else:
		d = int(d)
		for y in range(13):
			dp[i+1][(y*10+d)%13] += dp[i][y]
	for j in range(13):
		dp[i+1][j] %= mod
print(dp[n][5])