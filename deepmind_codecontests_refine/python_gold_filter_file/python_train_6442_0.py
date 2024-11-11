# AOJ 0191: Baby Tree
# Python3 2018.6.20 bal4u

while True:
	n, m = list(map(int, input().split()))
	if n == 0: break
	d =  [[0.0 for j in range(n)] for i in range(n)]
	for i in range(n): d[i] = list(map(float, input().split()))
	dp =  [[0.0 for j in range(n)] for k in range(m)]
	for i in range(n): dp[0][i] = 1
	for k in range(1, m):
		for i in range(n):
			for j in range(n):
				dp[k][j] = max(dp[k][j], dp[k-1][i]*d[i][j])
	ans = 0
	for i in range(n):
		if dp[m-1][i] > ans: ans = dp[m-1][i]
	print(format(ans, ".2f"))

