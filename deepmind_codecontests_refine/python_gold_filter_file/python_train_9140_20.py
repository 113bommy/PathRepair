N = int(input())
p = list(map(float, input().split()))

dp = [[0] * (N + 1) for _ in range(N + 1)]
dp[0][0] = 1

for i in range(N):
    for j in range(i + 1):
        dp[i + 1][j + 1] += dp[i][j] * p[i]
        dp[i + 1][j] += dp[i][j] * (1 - p[i])
ans = 0
for i in range(N // 2 + 1, N + 1):
    ans += dp[N][i]

print(ans)