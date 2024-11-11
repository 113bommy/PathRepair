s=input()
l=len(s)
mod = pow(10,9)+7

dp = [[0 for _ in range(13)] for _ in range(l+1)]
dp[0][0] = 1
keta = 1

for i in range(1,l+1):
	num = s[-i]
	if num == '?':
		for j in range(10):
			for k in range(13):
				dp[i][(j * keta + k) % 13] += dp[i-1][k] % mod
	else:
		num = int(num)
		for k in range(13):
			dp[i][(num * keta + k) % 13] += dp[i-1][k] % mod
	keta = keta*10  % 13
print(dp[l][5] % mod)