n,k=map(int,input().split())
m=10**9+7
dp=[[1 if i==1 else 0 for i in range(k+1)]for j in range(n+1)]
for j in range(1,k):
  for i in range(1,n+1):
    for ii in range(i,n+1,i):
      dp[ii][j+1]=(dp[ii][j+1]%m+dp[i][j]%m)%m
sums=0
for i in range(1,n+1):
  sums=(sums%m+dp[i][k]%m)%m
#ans = sum([ dp[i][k] for i in range(1, n + 1) ]) % m
print(sums%m)
