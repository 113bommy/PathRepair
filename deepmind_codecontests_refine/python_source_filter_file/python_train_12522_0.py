n,m=map(int,input().split())
s=input()
t=input()
dp=[]
for i in range(n+1):
  dp.append([])
  for j in range(m+1):
    dp[-1].append(0)
for i in range(n):
  for j in range(m):
    if s[i]==t[j]:
      dp[i+1][j+1]=dp[i][j]+2
    else:
      dp[i+1][j+1]=max(dp[i][j+1]-1,dp[i+1][j]-1)
ans=0
for i in range(n+1):
  for j in range(m+1):
    ans=max(ans,dp[i][j])
print(ans)
  