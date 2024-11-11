H, N = map(int, input().split())
AB = [tuple(map(int, input().split())) for _ in range(N)]
AB.sort(key=lambda x: x[1])

dp = [0] * (H + 1)
for h in range(1, H + 1):
    dp[h] = min([dp[h - a] + b for a, b in AB])

print(dp[-1])
