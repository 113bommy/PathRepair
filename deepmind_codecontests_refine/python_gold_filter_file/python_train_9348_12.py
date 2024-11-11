N, K = map(int, input().split())
import math
mod =10**9+7

l = []
l.append(N-K+1)
for i in range(1, K):
  a = l[i-1] * (N-K-i+1) * (K-i) // ((i+1)*i)
  l.append(int(a))

for j in l:
  print(j%mod)
