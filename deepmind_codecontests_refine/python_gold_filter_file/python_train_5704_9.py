H, W = [int(_) for _ in input().split()]

S = [input() for _ in range(H)]

INF = 10 ** 5
dp = [[INF] * (W + 1) for _ in range(H + 1)]
dp[0][0] = int(S[0][0] == '#')

for i in range(H):
    for j in range(W):

        # 横移動
        if j == 0:
            v1 = INF
        else:
            v1 = int(S[i][j - 1] == '.' and S[i][j] == '#') + dp[i][j - 1]

        # 縦移動
        if i == 0:
            v2 = INF
        else:
            v2 = int(S[i - 1][j] == '.' and S[i][j] == '#') + dp[i - 1][j]

        dp[i][j] = min(v1, v2, dp[i][j])
ans = dp[H - 1][W - 1]
print(ans)
