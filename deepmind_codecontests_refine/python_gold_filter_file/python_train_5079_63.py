from math import *

n, d, a = map(int, input().split())
damage_diff = [0] * n
damage = 0
p = sorted(tuple(map(int, input().split())) for _ in range(n))

j = 0
c = 0

for i in range(n):
  damage -= damage_diff[i]
  
  x, h = p[i]
  h -= damage
  if h <= 0: continue
  m = ceil(h/a)
  c += m
  m = m*a
  while j < n and p[j][0] - x <= 2 * d:
    j += 1

  if j < n:
    damage_diff[j] += m
  damage += m
print(c)