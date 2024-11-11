from math import gcd
a, b, c, d = map(int, input().split())
p, q = -1, -1
if d * a <= c * b:
  p = b * c - d * a
  q = a * c
else:
  p = a * d - b * c
  q = a * d
print("%d/%d" % (p / gcd(p, q), q / gcd(p, q)))