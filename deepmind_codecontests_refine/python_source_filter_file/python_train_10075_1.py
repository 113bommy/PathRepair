N,S=map(int,input().split())
A=list(map(int,input().split()))
mod=998244353
dp=[[0]*(S+1) for _ in range(N+1)]
dp[0][0]=1

for i in range(1,N+1):
  for j in range(S+1):
    dp[i][j]+=dp[i-1][j]*2
    if j-A[i-1]>=0:
      dp[i][j]+=dp[i-1][j-A[i-1]]
    dp[i][j]%=mod
print(dp[N][S])
    