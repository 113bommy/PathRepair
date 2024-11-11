dp = dict()
dp[0] = 0
dp[1] = -1e9
dp[2] = -1e9
s = input()
n = len(s)
sum = 0
ans = 0
for i in range(n):
	v = ord(s[i])-ord('0')
	sum += v
	sum %= 3
	dp[sum] = max(dp[0], dp[1], dp[2], dp[sum]+1)
	ans = max(ans, dp[sum])
print(ans)
