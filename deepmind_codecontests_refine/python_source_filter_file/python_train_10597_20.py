N, M = map(int, input().split())

INF = 10**9
dp = [[INF]*(1<<N) for _ in range(M+1)]
dp[0][0] = 0

for i in range(M):
  a, b = map(int, input().split())
  c = sum(map(lambda x: 1 << (int(x)-1), input().split()))
  for j in range(1<<N):
    k = j|c
    dp[i+1][j] = min(dp[i+1][j], dp[i][j])
    dp[i+1][k] = min(dp[i+1][k], dp[i][k], dp[i][j] + a)

ans = dp[-1][-1]

if ans == INF:
  print(-1)
else:
  print(ans)
