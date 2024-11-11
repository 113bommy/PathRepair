n = int(input())
a = list(map(int, input().split()))

dp=[]
for i in range(n):
	dp.append(0)
for i in range(n):
    dp[i][i] = a[i]

for i in range(n - 2, -1, -1):
    for j in range(i + 1, n):
        dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1])

print(dp[0][n - 1])