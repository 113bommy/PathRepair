h, w = map(int, input().split())
s = [input() for _ in range(h)]

INF = 10**9
dp = [[INF]*w for _ in range(h)]

dp[0][0] = 0 if s[0][0] == "." else 1

for i in range(h):
    for j in range(w):
        d, r = INF, INF

        if i != 0:
            d = dp[i - 1][j] + (s[i - 1][j] == "." and s[i][j] == "#")
        if j != 0:
            r = dp[i][j - 1] + (s[i][j - 1] == "." and s[i][j] == "#")

        dp[i][j] = min(r, d, dp[i][j])

print(dp[h-1][w-1])
