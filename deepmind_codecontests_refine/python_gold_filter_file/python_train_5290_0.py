n, a, b = map(int, input().split())
dp = [2 ** 60] * (n + 1)
dp[0] = 0
p = list(map(int, input().split()))
for i in range(n):
    dp[i + 1] = dp[0]
    dp[0] += a
    for j in range(i):
        if p[j] < p[i]:
            dp[i + 1] = min(dp[i + 1], dp[j + 1])
            dp[j + 1] += a
        else:
            dp[j + 1] += b
print(min(dp))