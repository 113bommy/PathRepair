N=int(input())
dp=[[0]*3 for i in range(N+1)]
for i in range(1,N):
  a=list(map(int,input().split()))
  for j in range(3):
    for k in range(3):
      if j==k:
        continue
      dp[i][k]=max(dp[i][k],dp[i-1][j]+a[k])
print(max(dp[-1]))