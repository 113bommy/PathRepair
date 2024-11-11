import sys

readline = sys.stdin.readline

ns = lambda: readline().rstrip()
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))

def modinv(x, mod):
    a, b = x, mod
    u, v = 1, 0
    while b:
        t = a // b
        a -= t * b; a, b = b, a
        u -= t * v; u, v = v, u
    return u % mod

def solve():
  n = ni()
  a = nl()
  m = max(a)
  mod = 998244353
  l = [0]*(m+1)
  for x in a:
    l[x] += x
  sieve = [1]*(m+1)
  sieve[0] = sieve[1] = 0
  for i in range(2, m+1):
    if sieve[i]:
      for j in range(m//i, 0, -1):
        sieve[j*i] = 0
        l[j] += l[j*i]
      sieve[i] = 1
  for i in range(m+1):
    l[i] = l[i] * l[i] % mod
  for i in range(2, m+1):
    if sieve[i]:
      for j in range(1, m//i + 1):
        l[j] -= l[j*i]
  s = -sum(a)
  for i in range(1, m+1):
    if l[i]:
      s = (s + l[i] * modinv(i, mod)) % mod
  print(s * modinv(2, mod) % mod)
  return

solve()