n = int(input())
a = list(map(int, input().split()))

INF = float('inf')
dp = [[INF] * (n+1) for _ in range(n+1)]

acum = [0] * (n+1)
for i, ai in enumerate(a):
    acum[i+1] += acum[i] + ai

for i in range(n+1):
    dp[i][i] = 0
    if i+1 <= n:
        dp[i][i+1] = 0

for l in range(2, n+1):
    for i in range(n-l+1):
        j = i + l
        for k in range(i+1, j):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + acum[j] - acum[i])

print(dp[0][n])

