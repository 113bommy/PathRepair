N,S = list(map(int, input().split()))
A = list(map(int, input().split()))

mod = 998244353
dp = [[0]*(S+1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(N):
  for j in range(S+1):
    if j - A[i] >= 0:
      dp[i+1][j] = (dp[i][j-A[i]]+dp[i][j]*2)%mod
    else:
      dp[i+1][j] = dp[i][j]*2
    
# print(dp)
print(dp[N][S])