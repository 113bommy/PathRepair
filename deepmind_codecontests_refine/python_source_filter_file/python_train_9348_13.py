n, k = map(int, input().split())
mod = 10**9+7
C = [[1], [1,1]]
for i in range(2, n+10):
  C.append([1] + [(C[i-1][j-1] + C[i-1][j])%mod for j in range(1, i)] + [1])
for i in range(1, k+1):
  if n-k+1 < i or k < i:
    print(1)
  else:
    print((C[n-k+1][i] * C[k-1][i-1])%mod)

