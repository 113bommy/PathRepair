n,a=map(int,input().split())
m=list(map(lambda x:int(x)-a,input().split()))
x=max(abs(max(m)),abs(min(m)))*n
dp=[[0for _ in range(2*x+1)]for i in range(n)]
dp[0][0+x]=1
dp[0][m[0]+x]=1
for i in range(1,n):
  y=m[i]
  for j in range(2*x+1):
    if 0<=j+y and j+y<2*x+1:
      dp[i][j+y]+=dp[i-1][j]
    dp[i][j]+=dp[i-1][j]
  #print(y,dp[i])
print(max(0,dp[n-1][0+x]-1))