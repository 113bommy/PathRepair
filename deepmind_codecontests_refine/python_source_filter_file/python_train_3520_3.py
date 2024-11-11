import sys
readline = sys.stdin.readline

# 区間DP
# dp[l][r] = 区間[l,r]のスライムを合体するときの最小コスト
# dp[l][r] = min(dp[l][m] + dp[m + 1][r]) + sum(l,r)

N = int(readline())
A = list(map(int,readline().split()))

A = [0] + A
for i in range(1,len(A)):
  A[i] += A[i - 1]

INF = 10 ** 10
dp = [[INF] * N for i in range(N)]
for i in range(N):
  dp[i][i] = 0

# 区間の長さが小さい順にループする(1～N)
for i in range(N): # 区間の長さ
  for l in range(N - i):
    r = l + i
    # lからrまでの区間で最小となるdp[l][m] + dp[m][r]の組み合わせを探す
    # lからrまでのAの累積和
    cums = A[r + 1] - A[l]
    for m in range(l,r):
      if dp[l][m] + dp[m + 1][r] + cums < dp[l][r]:
        dp[l][r] = dp[l][m] + dp[m + 1][r] + cums
        
print(dp[0][-1])