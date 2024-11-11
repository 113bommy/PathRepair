a, b, c, d = map(int, input().split())

dp = [[1 for i in range(d+1)] for j in range(c+1)]

mod = 998244353

for y in range(c+1):
    if y < a:
        continue
    for x in range(d+1):
        if x < b:
            continue
        if y == a and x == b:
            continue
        py = 0
        px = 0
        m = 0
        if y > a:
            py = dp[y-1][x] * x
        if x > b:
            px = dp[y][x-1] * y
        if y > a and x > b:
            m = dp[y-1][x-1] * (y-1) * (x-1)
        dp[y][x] = py + px - m
        dp[y][x] %= mod


print(dp[c][d])
