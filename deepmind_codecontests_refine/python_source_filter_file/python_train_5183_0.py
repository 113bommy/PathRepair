N=int(input())
A=list(map(int, input().split()))

dp = [[0 for i in range(2)] for j in range(N+1)]

if N in [2, 3]: print(max(A))
else:
  dp[2][0] = A[1]
  dp[2][1] = A[0]
  dp[3][0] = A[2]
  dp[3][1] = max(A[1], A[0])
  
  for i in range(4, N+1):
    if i % 2 == 0:
      dp[i][0] = max(max(dp[i-2][0], dp[i-2][1])+A[i-1], dp[i-1][1]+A[i-1])
      dp[i][1] = dp[i-2][1]+A[i-2]
    else:
      dp[i][0] = max(dp[i-2][0], dp[i-2][1])+A[i-1]
      dp[i][1] = max(dp[i-1][0], dp[i-1][1])

print(max(dp[-1][0], dp[-1][1]))