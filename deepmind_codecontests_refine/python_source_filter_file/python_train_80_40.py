n,m=map(int,input().split())
A=[int(input()) for _ in range(m)]
mod=10**9+7

dp=[0]*(n+1)
dp[0]=1
if 1 not in A:
   dp[1]=1

for i in range(2,n+1):
   if i not in A:
      dp[i]=dp[i-1]+dp[i-2]
print(dp[-1]%mod)