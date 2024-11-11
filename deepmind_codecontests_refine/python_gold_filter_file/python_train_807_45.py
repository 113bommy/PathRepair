n = int(input())
a = list(map(int, input().split()))

dp = [[0] * (n+1) for _ in range(n+1)]

p = []
for i in range(n):
    p.append((a[i], i))
p.sort(key=lambda x: -x[0])

for i in range(n):
    pi = p[i][1]
    for l in range(i+1):
        r = i - l
        dp[i+1][l+1] = max(dp[i+1][l+1], dp[i][l] + (pi-l)*a[pi])
        dp[i+1][l] = max(dp[i+1][l], dp[i][l] + ((n-r-1)-pi)*a[pi])

ans = 0
for i in range(n+1):
    ans = max(ans, dp[n][i])

print(ans)
