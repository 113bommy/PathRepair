N,T=map(int,input().split());AB=[list(map(int,input().split())) for _ in range(N)]
dp=[0]*T
AB.sort()
m=0
for a,b in AB:
  m=max(m,dp[-1]+b)
  for j in range(T-1,a-1,-1):
    dp[j] = max(dp[j],dp[j-a]+b)

print(m)
