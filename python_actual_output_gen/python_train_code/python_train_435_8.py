n,k=map(int,input().split());a=map(int,input().split())
dp=[0]*(k+1)
for i in range(1,k+1):
  for j in a:dp[i]=max((i-j>=0)*(dp[i-j]==0),dp[i])
print(["Second","First"][dp[-1]])