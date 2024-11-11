import math

N = int(input())
S = str(input())
K = len(S)
dp = []
ans = math.inf
for i in range(66):
	dp.append([])
	for j in range(66):
		dp[i].append(-1)
dp[K][0] = 0

def comp(x, y, v):
	if dp[x][y] == -1 or dp[x][y] > v:
		dp[x][y] = v

for i in range(K - 1, -1, -1):
	for j in range(1, K + 1):
		cur = 0
		if S[i] == '0':
			dp[i][j] = dp[i + 1][j - 1]
			continue
		for k in range(i, K):
			cur = cur * 10 + int(S[k])
			if cur > N:
				break
			if dp[k + 1][j - 1] != -1:
				comp(i, j, cur * (N**(j-1)) + dp[k + 1][j - 1])
for i in range(1, K + 1):
	if dp[0][i] != -1:
		ans = min(ans, dp[0][i])
print(ans)
