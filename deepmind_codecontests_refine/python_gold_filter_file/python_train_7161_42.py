def solve():
  N, T = map(int, input().split())
  A = [list(map(int, input().split())) for _ in range(N)] 
  A.sort()
  dp = [[0]*(T+1) for _ in range(N+1)]
  for i in range(N):
    for j in range(0,T+1):
      dp[i+1][j] = max(dp[i+1][j],dp[i][j])
      if j<T:
        t = min(T,j+A[i][0])
        dp[i+1][t] = max(dp[i+1][t],dp[i][j]+A[i][1])
  ans = dp[-1][-1]
  return ans
print(solve())