# Anton Timofeev
import sys

MOD = 998244353

n, k = map(int, sys.stdin.readline().split())
h = list(map(int, sys.stdin.readline().split()))
if k == 1:
	print(0)
	sys.exit()

dp = [[0] * (2 * n + 2) for _ in range(2)]
dp[0][0] = 1
for i in range(1, n + 1):
	m = i & 1
	for diff in range(-i, i + 1):
		if h[(i - 1) % n] != h[i % n]:
			dp[m][diff] = dp[m ^ 1][diff - 1]
			dp[m][diff] += dp[m ^ 1][diff + 1]
			dp[m][diff] += (dp[m ^ 1][diff] * (k - 2))
			dp[m][diff] %= MOD
		else:
			dp[m][diff] = dp[m ^ 1][diff] * k % MOD
	# print(f"i = {i}")
	# for diff in range(-i, i + 1):
	# 	print(f"{diff} -> {dp[m][diff]}")
	
print(sum(dp[n & 1][1:n + 1]) % MOD)
