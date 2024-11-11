from collections import Counter

n = int(input())
a = list(map(int, input().split()))
cnt = Counter(a)
p, q, r = cnt[1], cnt[2], cnt[3]

dp = [[[0.0] * (n + 1) for _ in range(n + 1)] for _ in range(n + 1)]

for k in range(r + 1):
    for j in range(r + q + 1):
        for i in range(n + 1):
            if not (0 < i + j + k <= n):
                continue
            if i > 0:
                dp[i][j][k] += dp[i - 1][j][k] * i
            if j > 0:
                dp[i][j][k] += dp[i + 1][j - 1][k] * j
            if k > 0:
                dp[i][j][k] += dp[i][j + 1][k - 1] * k
            dp[i][j][k] += n
            dp[i][j][k] /= (i + j + k)

print(dp[p][q][r])
