import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
  n = int(input())
  ab = [list(map(int,input().split())) for i in range(n)]
  a,b = list(zip(*ab))
  a = list(a)
  dp = [[10**18 for i in range(3)] for j in range(n+1)]
  dp[1][0] = 0
  dp[1][1] = b[0]
  dp[1][2] = 2*b[0]
  for i in range(2,n+1):
    ai,bi = a[i-1],b[i-1]
    mn = min(dp[i-1])
    if ai == a[i-2]:
      dp[i][0] = min(dp[i-1][1],dp[i][2])
      dp[i][1] = min(dp[i-1][0],dp[i][2])+bi
      dp[i][2] = min(dp[i-1][0],dp[i-1][1])+2*bi
    elif ai == a[i-2]+1:
      dp[i][0] = min(dp[i-1][0],dp[i-1][2])
      dp[i][1] = min(dp[i-1][0],dp[i-1][1])+bi
      dp[i][2] = mn+2*bi
    elif ai == a[i-2]-1:
      dp[i][0] = mn
      dp[i][1] = min(dp[i-1][1],dp[i-1][2])+bi
      dp[i][2] = min(dp[i-1][0],dp[i-1][2])+2*bi
    elif ai == a[i-2]+2:
      dp[i][0] = min(dp[i-1][0],dp[i-1][1])
      dp[i][1] = mn+bi
      dp[i][2] = mn+2*bi
    elif ai == a[i-2]-2:
      dp[i][0] = mn
      dp[i][1] = mn+bi
      dp[i][2] = min(dp[i-1][1],dp[i-1][2])+2*bi
    else:
      for j in range(3):
        dp[i][j] = mn+bi*j
  print(min(dp[-1]))