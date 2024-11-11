# -*- coding: utf-8 -*-

N = int(input())
A = list(map(int, input().split()))
A = sorted([(a, p) for p, a in enumerate(A)], reverse=True)


# dp[i][j] := i番目の幼児まで見て、左に詰める選択をj回行った場合のうれしさの最大値
dp = [[0] * (N + 1) for _ in range(N + 1)]
for i, (a, p) in enumerate(A):
    for j in range(i + 1):
        # 左に詰める場合
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (p - j) * a)

        # 右に詰める場合
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + ((N - (i - j) - 1) - p) * a)
#print(dp)
print(max(dp[-1]))
