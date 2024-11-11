import sys
sys.setrecursionlimit(10**7)
MOD = 10**9+7
n = int(input())
edges = [[] for _ in range(n)]
for _ in range(n-1):
	x, y = map(int, input().split())
	edges[x-1].append(y-1)
	edges[y-1].append(x-1)

dp = [[1 for _ in range(2)] for _ in range(n)]
#0が白, 1が黒

def dfs(cur, par):
	for e in edges[cur]:
		if e == par:
			continue
		dfs(e, cur)
		dp[cur][0] = dp[cur][0] * (dp[e][0]+dp[e][1]) % MOD
		dp[cur][1] = (dp[cur][1] * dp[e][0]) % MOD

	return

dfs(0, -1)
print(dp[0][0]+dp[0][1])