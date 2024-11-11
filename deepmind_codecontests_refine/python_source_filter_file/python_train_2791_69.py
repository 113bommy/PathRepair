n, k = map(int, input().split())
h = [int(i) for i in input().split()]
dp = [0]
for i in range(1, n):
    dp += [min([dp[i - j] + abs(h[i] - h[i - j]) for j in range(1, min(i, k) + 1)])]
print(dp[-1])