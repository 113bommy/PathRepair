l = int(input())
a = []
for i in range(l):
  a.append(int(input()))
  
dp=[[0]*5 for i in range(l+1)]

for i in range(0,l):
  if a[i]==0:
    even=2
  else:
    even=a[i]%2
  
  dp[i+1][0]=dp[i][0]+a[i]
  dp[i+1][1]=min(dp[i][0],dp[i][1]) + even
  dp[i+1][2]=min(dp[i][0],dp[i][1],dp[i][2]) + (a[i]+1)%2
  dp[i+1][3]=min(dp[i][0],dp[i][1],dp[i][2],dp[i][3]) + even
  dp[i+1][4]=min(dp[i][0],dp[i][1],dp[i][2],dp[i][3],dp[i][4]) + a[i]
  
print(min(dp[l]))
  