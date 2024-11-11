a, b, c, d = map(int, input().split())
dp = [[1 for _ in range(d - b + 1)] for _ in range(c - a + 1)]

mod = 998244353
for x in range(c - a + 1):
    for y in range(d - b + 1):
        if x == 0:
            if y > 0:
                dp[x][y] = dp[x][y - 1] * (a + x) % mod
        elif y == 0:
            dp[x][y] = dp[x - 1][y] * (b + y) % mod
        else:
            dp[x][y] = (((dp[x - 1][y] * (b + y)) + (dp[x][y - 1] * (a + x))) - (dp[x - 1][y - 1] * (a + x - 1) * (b + y - 1))) % mod

print(dp[-1][-1])