import sys
input = sys.stdin.buffer.readline
N = int(input())
A = list(map(int, input().split()))
zeta = [0] * (max(A) + 1)
mod = 998244353
for a in A:
  zeta[a] += a
for i in range(1, len(zeta)):
  for j in range(2 * i, len(zeta), i):
    zeta[i] += zeta[j]
for i in range(1, len(zeta)):
  zeta[i] *= zeta[i]
for i in range(len(zeta) - 1, 0, -1):
  for j in range(2 * i, len(zeta), i):
    zeta[i] -= zeta[j]
for a in A:
  zeta[a] -= a ** 2
for i in range(1, len(zeta)):
  zeta[i] //= 2
for i in range(1, len(zeta)):
  zeta[i] //= i
  res = (res + zeta[i]) % mod
print(res)