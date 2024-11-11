N = int(input())
A = list(map(int,input().split()))
A = [[a,i] for a,i in zip(A,range(1,N+1))]
A = sorted(A,reverse=True)
INF = float('inf')
dp = [[-INF] * (N+1) for _ in range(N+1)]
dp[0][0] = 0
ans = 0
for x_y in range(1,N+1):
  a = A[x_y-1]
  for x in range(x_y+1):
    y = x_y-x
    if x==0:
      dp[x][y] = dp[x][y-1] + a[0]*(N-y+1-a[1])
    elif y==0:
      dp[x][y] = dp[x-1][y] + a[0]*(a[1]-x)
    else:
      dp[x][y] = max(dp[x-1][y]+a[0]*(a[1]-x),dp[x][y-1] + a[0]*(N-y+1-a[1]))
    
    ans = max(ans,dp[x][y])
print(ans)