N,A=map(int,input().split())
x=list(map(int,input().split()))
dp=[[[0 for i in range(50*50)] for j in range(N+1) ]for k in range(N+1)]
dp[0][0][0]=1
for i in range(1,N+1):
  for j in range(N+1):
    for k in range(50*50):
      dp[i][j][k]=dp[i-1][j][k]
      if x[i-1]<= k and j>0: dp[i][j][k]+=dp[i-1][j-1][k-x[i-1]]
ans=0
for j in range(1,N+1):
  ans+=dp[N][j][j*A]
print(ans)