A,B,C,D = map(int,input().split())
MOD = 998244353

dp = [[0 for _ in range(D+1)] for _ in range(C+1)]
dp[A][B] = 1
#dp[i][j] ヨコi番目でそこまでの最大の高さがj

for i in range(A,C+1):
  for j in range(B,D+1):
    if i > A:
      dp[i][j] += dp[i-1][j]*j
    if j > B:
      dp[i][j] += dp[i][j-1]*i
    if i > A and j > B:
      dp[i][j] -= dp[i-1][j-1]*(i-1)*(j-1)
    dp[i][j] %= MOD

ans = dp[C][D]
print(ans)
      