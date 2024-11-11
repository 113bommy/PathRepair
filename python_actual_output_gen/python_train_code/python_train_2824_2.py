n, x = [int(x) for x in input().split()]
data = [int(x) for x in input().split()]
dp = [[0 for _ in range(3)] for _ in range(n + 1)]
for i, v in enumerate(data):
    i += 1
    dp[i][0] = max(dp[i - 1][0] + v, v)
    dp[i][1] = max(dp[i - 1][0] + v * x, v * x, dp[i - 1][1] + v * x)
    dp[i][2] = max(dp[i - 1][1] + x, dp[i - 1][2] + x)
print(max([x for d in dp for x in d]))
