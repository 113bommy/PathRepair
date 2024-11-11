import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

def intersection(p, q, eps = 10**-7):
    x1, y1, r1 = p
    x2, y2, r2 = q
    X = x2 - x1; Y = y2 - y1
    d = X**2 + Y**2
    c1 = r1**2; c2 = r2**2

    rc = (d + c1 - c2) / 2
    rs = d * c1 - rc ** 2
    
    if rs < eps: return list()
    
    rs **= .5
    p1x = x1 + (rc * X + rs * Y) / d
    p1y = y1 + (rc * Y - rs * X) / d
    p2x = x1 + (rc * X + rs * Y) / d
    p2y = y1 + (rc * Y + rs * X) / d
    return [(p1x, p1y), (p2x, p2y)]

eps = 10**-7
n,k = nm()
if k == 1: print(0); exit(0)
niku = [tuple(nm()) for _ in range(n)]
l = [c*(x**2+y**2)**.5 for x,y,c in niku]
l.sort()
hi = l[k-1]
lo = 0
for _ in range(50):
  mid = (hi+lo)/2
  l = [(x,y,mid/c) for x,y,c in niku]
  p = [(x,y) for x,y,c in niku]
  for i in range(n-1):
    for j in range(i+1,n):
      p.extend(intersection(l[i], l[j]))
  for x,y in p:
    f = sum((v-x)**2 + (w-y)**2 <= r**2 + eps for v,w,r in l)
    if f >= k:
      hi = mid
      break
  else:
    lo = mid
print(hi)
