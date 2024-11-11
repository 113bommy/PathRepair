n, t = map(int, input().split())
dp = [0] * (t + 1)
ab = [tuple(map(int, input().split())) for _ in range(n)]
#ab.sort()
max_b = [0] * n
max_b[-1] = ab[-1][1]
for i in range(n - 1, 0, -1):
    max_b[i - 1] = max(ab[i - 1][1], max_b[i])
for i in range(n - 1):
    a, b = ab[i]
    for j in range(t - 1, a-1, -1):
        dp[j] = max(dp[j - a] + b, dp[j])
    dp[t] = max(dp[t], dp[t-1] + max_b[i + 1])
print(max(dp))

