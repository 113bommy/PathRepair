t=int(input())
for pro in range(t):
  n, k=map(int, input().split())
  a=list(map(int, input().split(" ")))
  dp=[[0 for i in range(n+1)] for kk in range(n)]
  dp[0][0]=1 if a[0]==1 else 0
  for i in range(1, n):
    for j in range(i+2):
      if(a[i]==i+1-j):
        dp[i][j]=max(1+dp[i-1][j], dp[i][j-1])
      else:
        dp[i][j]=max(dp[i-1][j], dp[i-1][j-1])
  ans=-1
  for truck in range(n+1):
    if(dp[-1][truck]>=k):
      ans=truck
      break
  print(ans)