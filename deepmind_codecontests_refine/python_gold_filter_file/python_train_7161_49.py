N, T = map(int, input().split())
AB = []
for i in range(N):
  A, B = map(int, input().split())
  AB.append([A, B])

AB.sort()

dp = [[0 for t in range(T)] for i in range(N+1)]

ans = 0
for i, ab in enumerate(AB):
  ans = max(ans, dp[i][T-1] + ab[1])
  for t in range(T):
    if t < ab[0]:
      dp[i+1][t] = dp[i][t]
    else:
      dp[i+1][t] = max(dp[i][t-ab[0]] + ab[1], dp[i][t])

print(ans)
