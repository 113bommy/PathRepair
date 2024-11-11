n, d = map(int, input().split())

A = input()

dp = [float('inf')] * n
dp[0] = 0

for i in range(1, n):
	for j in range(max(i - d, 0), i):
		if A[i] == '1':
			dp[i] = max(dp[i], 1 + dp[j])


print(dp[-1] if dp[-1] != float('inf') else -1)