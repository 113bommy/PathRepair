import sys
input = sys.stdin.readline

n,m = map(int, input().split())
t = sorted([tuple(map(int, input().split())) for i in range(m)])
INF = 10 ** 18
dp = [0,0] + [INF] * (n-1) # 頂点1から各頂点(0~n)までの最短距離
for l,r,c in t:
  for i in range(r,l,-1):
    if dp[l] + c < dp[i]:
      dp[i] = dp[l] + c
    else:
      break
ans = dp[n]
if ans == INF:
  print(-1)
else:
  print(ans)
