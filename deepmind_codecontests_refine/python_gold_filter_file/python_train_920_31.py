r=lambda :map(int,input().split())
n,x=r()
*a,=r()
dp=[[0]*n for _ in range(n)]
for i,j in enumerate(a):
  dp[0][i]=j
for i in range(1,n):
  for j in range(n):
    dp[i][j]=min(dp[i-1][j],a[(j-i)%n])
print(min(i*x+sum(j) for i,j in enumerate(dp)))