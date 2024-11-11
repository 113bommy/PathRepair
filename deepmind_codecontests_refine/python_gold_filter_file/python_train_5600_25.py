INF = 10**9
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
dp = [[INF for _ in range(51)] for _ in range(1<<N)]
dp[0][0] = 0
for S in range(1 << N):
  j = bin(S).count("1")
  c = 0
  for i in range(N):
    if not (S & 1<<i):
      if (i - j) % 2 == 0:
        k = A[i]
      else:
        k = B[i]
      for l in range(k+1):
        dp[S|1<<i][k] = min(dp[S|1<<i][k],dp[S][l]+c)
      c += 1
ans = min(dp[-1])
print(-1 if ans == INF else ans)

