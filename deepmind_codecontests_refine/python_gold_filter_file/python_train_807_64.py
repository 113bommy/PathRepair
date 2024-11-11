import sys
input = sys.stdin.buffer.readline

n = int(input())
A = list(map(int, input().split()))
L = [(a, i+1) for i, a in enumerate(A)]
L.sort(reverse=True)
dp = [[-1]*(n+1) for _ in range(n+1)]
dp[0][0] = 0
for i in range(n+1):
  for j in range(n+1-i):
    a, idx = L[i+j-1]
    if i:
      dp[i][j] = max(dp[i][j], dp[i-1][j]+a*(idx-i))
    if j:
      dp[i][j] = max(dp[i][j], dp[i][j-1]+a*(n+1-j-idx))
ans = 0
for i in range(n+1):
  ans = max(ans, dp[i][n-i])
print(ans)