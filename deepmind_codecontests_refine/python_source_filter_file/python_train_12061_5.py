n, W = map(int, input().split())
dp = [[[0] * 301 for _ in range(n + 1)] for _ in range(n + 1)]
li = [list(map(int, input().split())) for _ in range(n)]
p = li[0][0]
for i, x in enumerate(li):
    w, v = x
    w -= p
    for j in range(i + 1):
        for k in range(301):
            if k >= w:
                if dp[i][j][k - w] + v > dp[i][j][k]:
                    dp[i + 1][j + 1][k] = dp[i][j][k - w] + v
                else:
                    dp[i + 1][j + 1][k] = dp[i][j + 1][k]
            else:
                dp[i + 1][j + 1][k] = dp[i][j + 1][k]
ans = 0
for i in range(n + 1):
    for k in range(301):
        if i * p + k <= W:
            ans = max(dp[n][i][k], ans)
print(ans)
