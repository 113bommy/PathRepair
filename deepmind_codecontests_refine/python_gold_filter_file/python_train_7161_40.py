n, t = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(n)]
ab.sort()
m = ab[-1][0]
dp = [0] * (m + t)
for a, b in ab:
    for j in range(t - 1, -1, -1):
        dp[a + j] = max(dp[a + j], dp[j] + b)
print(max(dp))