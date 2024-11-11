import sys
readline = sys.stdin.readline

N,K = map(int,readline().split())
A = list(map(int,readline().split()))
DIV = 10 ** 9 + 7

dp = [[0] * (K + 1) for i in range(N + 1)]
sdp = [[0] * (K + 1) for i in range(N + 1)]

dp[0][0] = 1
for j in range(len(dp[0])):
  sdp[0][j] = 1
  
for i in range(1, N + 1):
  for j in range(K + 1):
    dp[i][j] = sdp[i - 1][j]
    if j - A[i - 1] - 1 >= 0:
      dp[i][j] -= sdp[i - 1][j - A[i - 1] - 1]
    dp[i][j] %= DIV
  sdp[i][0] = dp[i][0]
  for j in range(1, K + 1):
    sdp[i][j] = sdp[i][j - 1] + dp[i][j]
    sdp[i][j] %= DIV
    
print(dp[N][K])