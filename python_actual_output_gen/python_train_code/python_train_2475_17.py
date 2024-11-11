n,t = map(int,input().split())
a = [list(map(int,input().split())) for i in range(n)]
a.sort()
DP = [[0 for i in range(t+3001)] for j in range(n+1)]
for i in range(1,n+1):
  for j in range(1,t+3001):
    if j-a[i-1][0] >= 0:
      DP[i][j] = max(DP[i-1][j],DP[i-1][j-a[i-1][0]]+a[i-1][1])
    else:
      DP[i][j] = DP[i-1][j]
ans = 0
for i in range(n):
  ans = max(ans,DP[i][t-1]+a[i][1])
  print(ans)