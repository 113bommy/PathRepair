n,w=map(int,input().split())
A=[list(map(int,input().split())) for i in range(n)]

dp=[float("inf")]*(10**3+1)
dp[0]=0
for i in range(n):
  for j in range(10**3,A[i][1]-1,-1):
    dp[j]=min(dp[j],dp[j-A[i][1]]+A[i][0])
ans=0
for v,e in enumerate(dp):
  if e<=w:
    ans=v
print(ans)
