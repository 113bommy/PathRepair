R,C,K=map(int,input().split())
l=[[0] * C for i in range(R)]
for i in range(K):
  a,b,c=map(int,input().split())
  a-=1
  b-=1
  l[a][b]=c
dp=[0]*C
for i in range(R):
  ndp=[0]*C
  kdp=[0]*4
  kdp[0]=dp[0]
  kdp[1]=l[i][0]+dp[0]
  ndp[0]=dp[0]+kdp[1]
  for j in range(1,C):
    kdp[0]=max(kdp[0],dp[j])
    for k in range(2,-1,-1):
      kdp[k+1]=max(kdp[k+1],kdp[k]+l[i][j])
    ndp[j]=max(kdp)
  dp=ndp
print(dp[C-1])