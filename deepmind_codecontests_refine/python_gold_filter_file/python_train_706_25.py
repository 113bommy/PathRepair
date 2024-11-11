N,K = map(int,input().split())
A = list(map(int,input().split()))
dp = []
for i in range(N):
  L = [0]*(K+1)
  dp.append(L)
for i in range(A[0]+1):
  dp[0][i] = 1
for i in range(1,N):
  cur = [0]*(K+2)
  for j in range(K+1):
    cur[j+1] = (cur[j]+dp[i-1][j])%(10**9+7)
  for k in range(K+1):
    if k > A[i]:
      dp[i][k] = cur[k+1]-cur[k-A[i]]
    else:
      dp[i][k] = cur[k+1]
print(dp[N-1][K]%(10**9+7))