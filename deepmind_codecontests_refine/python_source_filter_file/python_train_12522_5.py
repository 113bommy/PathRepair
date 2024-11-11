import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=input().rstrip()
b=input().rstrip()
dp=[[0]*(m+1) for i in range(n+1)]
for i in range(n):
  for j in range(m):
    if a[i]==b[j]:
      dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+2)
    else:
      dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])-1
ans=0
for i in range(1,n+1):
  for j in range(1,m+1):
    ans=max(ans,dp[i][j])
print(ans)