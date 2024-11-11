N, K = map(int, input().split())
MOD = 10**9 + 7
import math

def c(n, r):
  return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

for i in range(1, K+1):
  if i<=(N-K+1):
  	print((c(N-K+1, i) * c(K-1, i-1)) % MOD)
  else:
    break