n,a=map(int,input().split())
x=list(map(int,input().split()))
y=[]
for i in x:
  y.append(i-a)
s=2*n*a
dp=[[0 for i in range(s+1)] for j in range(n+1)]
dp[0][n*a]=1
for i in range(n):
  for j in range(s+1):
    x=j-y[i]
    if(0<=x and x<=2*n*a):
      dp[i+1][j]=dp[i][j-y[i]]+dp[i][j]
    else:
      dp[i+1][j]=dp[i][j]

print(dp[n][n*a]-1)