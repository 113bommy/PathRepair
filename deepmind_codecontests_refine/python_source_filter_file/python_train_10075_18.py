N, S = map(int,input().split())
A = [int(s) for s in input().split()]
DP = [[0 for j in range(S + 1)] for i in range(N + 1)]
mod = 998244353
DP[0][0] = 1

for i in range(N):
  for j in range(S + 1):
    DP[i + 1][j] += 2 * DP[i][j]
    DP[i + 1][j] %= mod
    if j + A[i] <= S:
      DP[i + 1][j + A[i]] += DP[i][j]
      DP[i + 1][j] %= mod

print(DP[N][S])