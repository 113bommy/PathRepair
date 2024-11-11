s = input()
mod = 10 ** 9 + 7

l = len(s)
s = [int(e) if e != "?" else -1 for e in s]
dp = [[0] * 13 for _ in range(l + 1)]
dp[0][0] = 1

for i in range(l):
	for k in range(10):
		if s[i] == -1 or s[i] == k:
			for j in range(13):
				nj = (j * 10 + k) % 13
				dp[i+1][nj] += dp[i][j]
				dp[i+1][nj] %= mod

ans = dp[l][5]
print(ans)
