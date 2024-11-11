N=int(input())
P=list(map(float,input().split()))
dp=[[0]*(N+1) for i in range(N+1)]
dp[0][0]=1
for i in range(1,N+1):
  for j in range(N+1):
    dp[i][j]=dp[i-1][j-1]*P[i-1]+dp[i-1][j]*(1-P[i-1])
ans=0

for i in range(N//2+1,N+1):
  ans+=dp[-1][i]
print(ans)