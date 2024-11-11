def makelist(n, m, p):
	return [[[0 for k in range(p)] for i in range(m)] for j in range(n)]

N, A = map(int, input().split())
x = list(map(int, input().split()))

dp = makelist(N+1, N+1, N*A+1)
dp[0][0][0] = 1
for i in range(N):
	for j in range(i+1):
		for k in range(N*A):
			if k + x[i] <= N * A:
				dp[i+1][j+1][k+x[i]] += dp[i][j][k]
			dp[i+1][j][k] += dp[i][j][k]

ans = 0
for i in range(1, N+1):
	ans += dp[N][i][i*A]

print(ans)