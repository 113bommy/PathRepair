import math

def dist(a, b):
  x = abs(a[0] - b[0])
  y = abs(a[1] - b[1])
  return math.sqrt(x * x + y * y)

def path(a, b, c):
  return dist(a, b) + dist(b, c)

def findb(ap, bp, tp, gb):
  adiff = 0.0
  abest = set()
  for gp in gb:
    x = dist(gp, tp) - dist(ap, gp)
    if x > adiff:
      adiff = x
      abest = gp

  bdiff = 0.0
  for gp in gb:
    if gp == abest:
      continue
    x = dist(gp, tp) - dist(bp, gp)
    if x > bdiff:
      bdiff = x

  return adiff + bdiff


def solve():
  ax, ay, bx, by, tx, ty = [int(x) for x in input().split()]
  n = int(input())
  gb = []
  for _ in range(n):
    a, b = [int(x) for x in input().split()]
    gb.append((a, b))

  ap = (ax, ay)
  bp = (bx, by)
  tp = (tx, ty)
  total = 0.0
  for gp in gb:
    total += dist(gp, tp) * 2

  aa = findb(ap, bp, tp, gb)
  bb = findb(bp, ap, tp, gb)

  if aa > bb:
    print(total - aa)
  else:
    print(total - bb)

if __name__ == '__main__':
  solve()
