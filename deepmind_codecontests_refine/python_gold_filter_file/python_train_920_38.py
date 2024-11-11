n, x = map(int, input().split())
a = list(map(int, input().split()))

INF = float('inf')
dp = [[INF] * (n+10) for _ in range(n)]

for i in range(n):
    for k in range(n):
        if k == 0:
            dp[i][k] = a[i]
        else:
            dp[i][k] = min(dp[i][k-1], a[(i-k)%n])

ans = INF

for k in range(n):
    tmp = x * k
    for i in range(n):
        tmp += dp[i][k]
    ans = min(ans, tmp)

print(ans)
