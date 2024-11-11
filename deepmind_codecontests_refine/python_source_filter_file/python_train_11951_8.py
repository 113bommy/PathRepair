n, k = map(int, input().split())
h = [0] + list(map(int, input().split()))
inf = 10 ** 13
dp = [[0] * (k + 1)]
for i in range(1, n + 1):
    dp.append([inf] * (k + 1))
    for j in range(i):
        for u in range(i - j - 1, k + 1):
            dp[-1][u] = min(dp[-1][u], dp[j][u - i + j + 1] + max(h[i] - h[j], 0))
print(min(dp[-1]))
