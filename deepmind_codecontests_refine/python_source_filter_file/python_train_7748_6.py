n,k=map(int,input().split())
mod=10**9+7
l=[[] for i in range(2*10**3+1)]
for i in range(1,2*10**3+1):
  for j in range(1,i+1):
    if i%j==0:
      l[i].append(j)
dp=[[0]*(n+1) for i in range(k+1)]
for i in range(1,n+1):
  dp[1][i]=1
for i in range(2,k+1):
  for j in range(1,n+1):
    for x in l[j]:
      dp[i][j]+=dp[i-1][j//x]
      dp[i][j]%=mod
print(sum(dp[-1]))