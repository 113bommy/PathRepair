h, n = map(int, input().split())
inf = 10**11

# dp[i]: 体力iを減らす魔力の最小値
dp = [inf] * 20000
dp[0] = 0

for _ in range(n):
    a, b = map(int, input().split())
    for j in range(h):
        dp[j+a] = min(dp[j] + b, dp[j+a])

print(min(dp[h:]))