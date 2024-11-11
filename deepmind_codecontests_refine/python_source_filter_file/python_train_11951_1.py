n, k = map(int, input().split())
h = list(map(int, input().split()))

#dp[a][b][c]: aまで見てb個消していて消してない右端がcのときの最小値(ぜんぶ1-indexed)
dp = [[[10**12 for _ in range(n+1)] for _ in range(k+1)] for _ in range(n+1)]
dp[0][0][0] = 0

for a in range(n):
	for b in range(k+1):

		for c in range(a+1):
			#h[a]を消す場合
			if b < k:
				dp[a+1][b+1][c] = min(dp[a+1][b+1][c], dp[a][b][c])

			#h[a]を消さない場合
			dp[a+1][b][a+1] = min(dp[a+1][b][a+1], dp[a][b][c] + max(0, h[a] - h[c-1]))

print(min(dp[n][k])+1)