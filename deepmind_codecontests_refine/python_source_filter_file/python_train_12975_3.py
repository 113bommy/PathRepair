import sys

#f = open('input', 'r')
f = sys.stdin
n, r = map(int, f.readline().split())
xs = map(int, f.readline().split())

import math

xy_before = []
ans = []
for x in xs:
  max_y = 2
  for bx, by in xy_before:
    if abs(x - bx) <= 2*r:
      if max_y < by + math.sqrt((2*r)**2 - (x-bx)**2):
        max_y = by + math.sqrt((2*r)**2 - (x-bx)**2)
  ans.append(max_y)
  xy_before.append((x, max_y))

print(' '.join(map(str, ans)))
