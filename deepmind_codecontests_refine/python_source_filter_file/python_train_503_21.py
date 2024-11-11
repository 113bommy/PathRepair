N, A = map(int, input().split())
x= [int(i) for i in input().split()]
X = max(x)
dp = [[[0]*(X*N+1) for i in range(N+1)] for j in range(N+1)]
dp[0][0][0] = 1
ans = 0

for j in range(1,N+1):
  for k in range(j+1):
    for s in range(X*N+1):
      dp[j][k][s] = dp[j-1][k][s]
      if s >= x[j-1]:
        dp[j][k][s] += dp[j-1][k-1][s-x[j-1]]
      
for i in range(1,N+1):
  ans += dp[-1][i][i*A]
  if (i+1)*A >= X*N:
    break
print(ans)