from math import floor

def bounded_sum(l, p1, p2):
  r = 0
  for i in range(p1, p2 + 1):
    r += l[i]
  return r


def solve(n, k, a):
  r = 0
  for i in range(k):
    r += a[i]
  aux = r
  for j in range(k, n):
    r += a[i] + a[i-k]
    aux += r
  return aux/(n - k + 1)


N, K = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
print("{0:.12f}".format(solve(N, K, A)))