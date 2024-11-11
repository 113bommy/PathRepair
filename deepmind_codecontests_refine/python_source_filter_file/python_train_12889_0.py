N, W = map(int, input().split())
INF = 10**10
dp = [INF]*(N*1000+1)
dp[0] = 0
for i in range(N):
  w, v = map(int, input().split())
  for j in range(N*1000, v-1, -1):
    dp[j] = min(dp[j], dp[j-v]+w)

for i in range(N*1000)[::-1]:
  if dp[i]>0 and dp[i]<=W:
    print(i)
    break