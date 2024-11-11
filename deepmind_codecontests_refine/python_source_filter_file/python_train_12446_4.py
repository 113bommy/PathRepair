from math import gcd
def exd_gcd(a, b):
  # always return as POSITIVE presentation
  if a % b == 0:
    return 0, (1 if b > 0 else -1)
  x, y = exd_gcd(b, a % b)
  return y, x - a // b * y
def interval_intersect(a, b, c, d):
  if b <= a or d <= c:
    return 0
  if c < a:
    a, b, c, d = c, d, a, b
  if c < b:
    return min(b, d) - c
  else:
    return 0
def ceil(a, b):
  return (a + b - 1) // b

a1, b1, a2, b2, L, R = map(int, input().split())
g = gcd(a1, a2)
if (b1 - b2) % g != 0:
  print(0)
  exit(0)
k, l = exd_gcd(a1, a2)
l = -l
k *= (b2 - b1) // g
l *= (b2 - b1) // g
d1 = a2 // g
d2 = a1 // g
assert(k * a1 + b1 == l * a2 + b2)
arb = 3238
assert((k + arb * d1) * a1 + b1 == (l + arb * d2) * a2 + b2)
L1, R1 = ceil(max(0, ceil(L - b1, a1)) - k, d1), ((R - b1) // a1 - k) // d1
L2, R2 = ceil(max(0, ceil(L - b2, a2)) - k, d2), ((R - b2) // a2 - k) // d2
print(interval_intersect(L1, R1 + 1, L2, R2 + 1))
