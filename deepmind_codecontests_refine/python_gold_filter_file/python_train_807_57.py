n = int(input())
A = list(map(int, input().split()))

p = []
for i, v in enumerate(A):
  p.append((v, i))
  
p.sort(reverse=True)

dp = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(n):
  k = p[i][0]
  r = p[i][1]
  for x in range(i + 1):
    y = i - x
    dp[x + 1][y] = max(dp[x + 1][y], dp[x][y] + abs(r - x) * k)
    dp[x][y + 1] = max(dp[x][y + 1], dp[x][y] + abs(r - (n - 1 - y)) * k)

ans = 0
for i in range(n):
  ans = max(ans, dp[i][n-i])
  
print(ans)