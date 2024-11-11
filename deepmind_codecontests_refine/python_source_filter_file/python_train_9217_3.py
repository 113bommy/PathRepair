n = int(input())
sp = list(map(int, input().split()))
dp = [[0, 0, 0] for i in range(n + 1)]
maxc = 0
for i in range(1, n + 1):
    dp[i][0] = dp[i - 1][0]
    dp[i][1] = dp[i - 1][1]
    dp[i][2] = dp[i - 1][2]
    if sp[i - 1] % 2 == 1:
        dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1, dp[i][1])
    if sp[i - 1] >= 2:
        dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1, dp[i][2])
    maxc = max(maxc, max(dp[i]))
print(n - maxc)
