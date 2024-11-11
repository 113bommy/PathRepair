N,M=map(int,input().split())
dp=[-1]*N
dp[-1]=1
dp+=[1]
mod=10**9+7
for i in range(M):
  a=int(input())
  dp[a]=0
i=N-2
while i>=0:
  if dp[i]==-1:
    dp[i]=(dp[i+1]+dp[i+2])%mod
  i-=1
print(dp[0])
