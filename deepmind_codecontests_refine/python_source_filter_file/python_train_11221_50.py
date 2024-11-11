INT_MAX = 10**8
h, n = map(int, input().split())
e = [tuple(map(int, input().split())) for _ in range(n)]

dp = [INT_MAX] * (h+1)
dp[0] = 0
for i in range(1, h+1):
  for a, b in e:
    c = dp[max(0, i - a)] + b
    dp[i] = min(dp[i], c)

print(dp[h])