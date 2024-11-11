r=range
M=10**9+7
n=input()
d=int(input())
dp=[[[0,0]for j in r(d)]for i in r(len(n)+1)]
dp[0][0][0]=1
for i,x in enumerate(map(int,n),1):
  for j in r(10):
    for k in r(d):
      dp[i][(j+k)%d][1]+=dp[i-1][k][1]
      dp[i][(j+k)%d][1]%=M
      if j<x:
        dp[i][(j+k)%d][1]+=dp[i-1][k][0]
        dp[i][(j+k)%d][1]%=M
      if j==x:
        dp[i][(j+k)%d][0]+=dp[i-1][k][0]
        dp[i][(j+k)%d][0]%=M
print(sum(dp[-1][0])%M-1)