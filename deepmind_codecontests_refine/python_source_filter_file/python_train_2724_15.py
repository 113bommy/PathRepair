from collections import defaultdict
n1, n2, k1, k2 = [int(_) for _ in input().split()]

dp = defaultdict(int)
mod = 10**8

def calc(a, b, c, d):
	global dp
	temp = (a, b, c, d)
	if temp in dp:
		return dp[temp]
	res = 0
	
	if a > 0 and c < k1:
		res += calc(a - 1, b, c + 1, 0)
	if b > 0 and d < k2:
		res += calc(a, b - 1, 0, d + 1)
	if a == 0 and b == 0:
		res = 1
	dp[temp] = res % mod
	
	#print(dp)

	return dp[temp]

print(calc(n1, 1, 0, 0))
