n=int(input())
xh=[list(map(int,input().split())) for i in range(n)]+[[10**18,1]]
xh.sort()
dp=[[0]*3 for i in range(n)]
dp[0][0]=1
dp[0][1]=0
if n==1:
  dp[0][2]=1
elif xh[0][0]+xh[0][1]<=xh[1][0]:
  dp[0][2]=1
else:
  dp[0][2]=0
for i in range(1,n):
  x,h=xh[i]
  if xh[i-1][0]<=x-h:
    dp[i][0]=max([dp[i][0],dp[i-1][0]+1,dp[i-1][1]])
  if xh[i-1][0]+xh[i-1][1]<=x-h:
    dp[i][0]=max(dp[i][0],dp[i-1][2]+1)
  dp[i][1]=max(dp[i-1])
  if x+h<=xh[i+1][0]:
    dp[i][2]=max(dp[i-1])+1
  else:
    dp[i][2]=max(dp[i-1])
print(max(dp[-1]))