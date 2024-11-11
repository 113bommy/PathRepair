n,t=map(int,input().split())
l=[list(map(int,input().split())) for _ in range(n)]
dp=[0]*(t+max(l)[0])
l.sort()
for a,b in l:
  for i in range(0,t+a)[::-1]: 
    if i-a>=0:
      dp[i]=max(dp[i],dp[i-a]+b)
print(max(dp[t:]))