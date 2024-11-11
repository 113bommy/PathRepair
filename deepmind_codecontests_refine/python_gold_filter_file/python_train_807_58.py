n = int(input())
a = list(map(int, input().split()))
b = []
for i, v in enumerate(a):
    b.append([v, i])
b.sort(reverse = True)
dp = [[0] * (n+1) for _ in range(n+1)]
ans = 0

for i in range(n+1):
    for j in range(n+1-i):
        if i > 0:
            dp[i][j] = max(dp[i][j], dp[i-1][j] + b[i+j-1][0] * (b[i+j-1][1] - (i - 1)))
        if j > 0:
            dp[i][j] = max(dp[i][j], dp[i][j-1] + b[i+j-1][0] * ((n - j) - b[i+j-1][1]))

for i in range(n+1):
    ans = max(ans, dp[i][n-i])

print(ans)