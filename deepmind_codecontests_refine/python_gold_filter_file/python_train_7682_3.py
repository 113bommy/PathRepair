from math import factorial as f
N, M, K = map(int, input().split())
mod = 10 ** 9 + 7

def combi(n, r):
  return f(n) // (f(n - r) * f(r)) % mod

res = 0
c = combi(N * M - 2, K - 2)
for i in range(1, N):
  res += ((N - i + 1) * (N - i) // 2) * c * M * M % mod
  res %= mod

for i in range(1, M):
  res += ((M - i + 1) * (M - i) // 2) * c * N * N % mod
  res %= mod

print(res % mod)

