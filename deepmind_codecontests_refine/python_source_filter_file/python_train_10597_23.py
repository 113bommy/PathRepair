N,M = map(int,input().split())
dp = [float('inf')]*2 ** N
dp[0] = 0
for _ in range(N):
  a,b = map(int,input().split())
  c = sum([2**(int(i)-1) for i in input().split()])
  for s in range(2**N):
    t = s|c
    if dp[t] > dp[s] + a:
      dp[t] = dp[s] +a
ans = dp[-1]
if dp[-1] == float('inf'):
  print(-1)
else:
  print(ans)