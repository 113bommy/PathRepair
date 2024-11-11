H, N = map(int, input().split())
dp = [ 1001001001 for _ in range(H+1)]
dp[0] = 0
for i in range(N):
  A, B = map(int, input().split())
  for j in range(H):
    nj = min(j+A, H)
    dp[nj] = min(dp[nj], dp[j] + B)

print(dp[H])