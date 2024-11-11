n = int(input())
a = list(map(int, input().split()))
a = [[e, i] for i, e in enumerate(a, 1)]

a.sort(reverse=True)

dp = [[0] * (n + 1) for _ in range(n + 1)]

for t, (e, idx) in enumerate(a, 1):
    for i in range(1, t + 1):
        j = t - i
        dp[i][j] = max(dp[i][j], dp[i-1][j] + e * abs(idx - i))

    for j in range(1, t + 1):
        i = t - j
        dp[i][j] = max(dp[i][j], dp[i][j-1] + e * abs(idx - (n - j + 1)))

ans = 0
for i in range(1, n + 1):
    j = n - i
    ans = max(ans, dp[i][j])

print(ans)
