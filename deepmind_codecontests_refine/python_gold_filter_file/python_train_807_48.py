n=int(input())
arr=list(map(int,input().split()))
arr=[[arr[i],i] for i in range(n)]
arr=sorted(arr,reverse=True,key=lambda x:x[0])
dp=[[-1]*(n+1) for _ in range(n+1)]
dp[0][0]=0
for i in range(n):
  for j in range(n):
    if dp[i][j]==-1:
      continue
    dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+arr[i][0]*abs(arr[i][1]-j))
    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+arr[i][0]*abs(n-1-(i-j)-arr[i][1]))
print(max(dp[-1]))