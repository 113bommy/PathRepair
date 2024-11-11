n,m=map(int,input().split())
mod=10**9+7
s=list(map(int,input().split()))
t=list(map(int,input().split()))
dp=[[0 for i in range(m+1)] for i in range(n+1)]
sum=[[0 for i in range(m+1)] for i in range(n+1)]
for i in range(1,n+1):
  for j in range(1,m+1):
    if s[i-1]==t[j-1]:
      dp[i][j]=(sum[i-1][j-1]+1)%mod
    else:dp[i][j]=0
    sum[i][j]=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+dp[i][j])%mod
print(sum[-1][-1]%mod)
