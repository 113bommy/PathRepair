n, h = map(int, input().split())
a = [int(i) for i in input().split()]
dp = [0]*(n+1)
if a[0] == h or a[0] + 1 == h:
		dp[0] = 1
MOD = 10**9 + 7
for i in range(1, n):
		d = h - a[i]
		if d < 0:
			continue
		if a[i - 1] + d - 1 == h & d > 0:
			dp[i] += dp[i - 1]
		if a[i - 1] + d + 1 == h:
			dp[i] += dp[i - 1] * (d + 1)
		if a[i - 1] + d == h:
			dp[i] += dp[i - 1] * (d + 1)
		dp[i] %= MOD
if a[n - 1] == h or a[n - 1] + 1 == h:
  print(dp[n-1])
else:
  print(0)