a = list(input())
b = list(input())

if len(a) == 0 or len(b) == 0:
	print(max(len(a),len(b)))

else:
	dp = [[None for i in range(len(b)+1)] for j in range(len(a)+1)]
	for i in range(len(a)+1):
		dp[i][0] = i
	for i in range(len(b)+1):
		dp[0][i] = i

	for i in range(len(a)+1):
		for j in range(len(b)+1):
			aaa = dp[i-1][j-1] if a[i-1] == b[j-1] else dp[i-1][j-1]+1
			dp[i][j] = min(aaa,dp[i-1][j] + 1,dp[i][j-1]+1)

print(dp[-1][-1])
