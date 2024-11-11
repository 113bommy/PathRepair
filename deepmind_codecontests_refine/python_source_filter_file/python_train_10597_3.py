INF = 10**8

N, M = map(int, input().split())
n = 2 ** N
dp = [0] + [INF]*(n - 1)

for _ in range(M):
  a, b = map(int, input().split())
  c = sum(map(lambda x:2**(x-1), list(map(int, input().split()))))
  for i in range(n):
    dp[i | c] = min(dp[i] + a, dp[i | c])
  
if dp[-1] == INF:
  print(-1)
else:
  print(dp[-1])