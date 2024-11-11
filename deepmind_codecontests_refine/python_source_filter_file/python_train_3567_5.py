import pprint
n, r1, r2, r3, d = map(int, input().split())
*arr, = map(int, input().split())

dp = [[0] * (n + 1) for _ in range(2)]

dp[0][0] = -d
dp[0][1] = 2 * n * r2 + 2 * n * d
for i in range(n):
    fast_kill = arr[i] * r1 + r3
    slow_kill = min((arr[i] + 2) * r1, r2 + r1)
    # print(i, arr[i], fast_kill, slow_kill)
    extra = -d if i == n - 1 else 0
    dp[0][i + 1] = min(dp[0][i] + fast_kill, dp[1][i] + fast_kill + extra, dp[1][i] + slow_kill) + d
    dp[1][i + 1] = dp[0][i] + slow_kill + 3 * d

# pprint.pprint(dp)
print(min(dp[0][-1], dp[1][-1]))
