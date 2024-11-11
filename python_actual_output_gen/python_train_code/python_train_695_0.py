n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))

i = 0
j = 0
ans = 0

start = [0] * n

for _ in range(n):
	while j < i and a[i] - a[j] > 5:
		j += 1

	start[i] = j
	i += 1

dp = [([0] * (k + 1)) for _ in range(n)]

for i in range(n):
	dp[i][1] = 1

for i in range(1, n):
	for j in range(1, k+1):
		lastgroup = 0
		if start[i] >= 1:
			lastgroup = dp[start[i]-1][j-1]
		
		dp[i][j] = max(dp[i-1][j], lastgroup + (i - start[i]) + 1)

	
print(dp[-1][-1])