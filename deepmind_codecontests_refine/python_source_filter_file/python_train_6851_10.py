l = int(input())
a = [int(input()) for _ in range(l)]

INF = float('inf')
dp = [[INF] * 5 for _ in range(l+10)]
dp[0][0] = 0

for i in range(l):
    for j in range(4):
        dp[i][j+1] = min(dp[i][j+1], dp[i][j])

    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a[i])
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a[i] % 2 if a[i] > 0 else dp[i][1] + 2)
    dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + (a[i] + 1) % 2)
    dp[i + 1][3] = min(dp[i + 1][3], dp[i][3] + a[i] % 2 if a[i] > 0 else dp[i][1] + 2)
    dp[i + 1][4] = min(dp[i + 1][4], dp[i][4] + a[i])

ans = float('inf')
for j in range(5):
    ans = min(ans, dp[l][j])

print(ans)