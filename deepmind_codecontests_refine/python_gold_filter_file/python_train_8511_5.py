# gcdと逆元
def inv_gcd(a, b):
  a = a % b
  if a == 0: return (b, 0)
  s, t = b, a
  m0, m1 = 0, 1
  while t:
    u = s // t
    s -= t * u
    m0 -= m1 * u
    s, t = t, s
    m0, m1 = m1, m0
  if m0 < 0: m0 += b // s
  return (s, m0)

import math
def prime(x):
  p = {}
  last = math.floor(x ** 0.5)
  if x % 2 == 0:
    cnt = 1
    x //= 2
    while x & 1 == 0:
      x //= 2
      cnt += 1
    p[2] = cnt
  for i in range(3, last + 1, 2):
    if x % i == 0:
      x //= i
      cnt = 1
      while x % i == 0:
        cnt += 1
        x //= i
      p[i] = cnt
  if x != 1:
    p[x] = 1
  return p

N = int(input())

N *= 2
p = prime(N)
L = []
for key in p.keys():
  L.append(key)

M = len(L)
ans = N - 1
for i in range(1, (1 << M) - 1):
  x = 1
  cnt = 0
  while i:
    if i & 1:
      key = L[cnt]
      x *= pow(key, p[key])
    i >>= 1
    cnt += 1
  y = N // x
  iv = inv_gcd(x, y)[1]
  if iv == 0: continue
  ans = min(ans, iv * x - 1)

print(ans)