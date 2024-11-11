n,m = map(int, input().split())

a = [int(i) for i in input().split()]

l = [0,2,5,5,4,5,6,3,7,6]
inf = float("INF")
dp = [-inf] * (n+10)
d = [-inf] * (n+10)
dp[0] = 0
d[0] = 0
for i in range(n):
  if dp[i] == -inf: continue
  tmp = dp[i]
  k = d[i]
  for ai in a:
    dp[l[ai] + i] = max(dp[l[ai] + i], dp[i] + k * ai, dp[i] * 10 + ai)
    d[i + l[ai] + i] = max(d[i + l[ai] + i], k + 1)
print(dp[n])
