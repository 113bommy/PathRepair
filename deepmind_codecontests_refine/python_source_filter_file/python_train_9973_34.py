N = int(input())
xy = [list(map(int, input().split())) for _ in range(N)]

D = []
import math

for i in range(N):
  x, y = xy[i]
  t = math.atan2(y, x)
  t = math.degrees(t)
  if t < 0:
    t += 360
  D.append([t, x, y])

import copy
D.sort()
D = D + copy.deepcopy(D)
for i in range(N, N + N):
  D[i][0] += 360

ans = 0
for i in range(N):
  x, y = 0, 0
  d = D[i][0]
  for j in range(i, i + N):
    t = D[j][0]
    if t - d > 180:
      break
    x += D[j][1]
    y += D[j][2]
  l = (x ** 2 + y ** 2) ** (1 / 2)
  ans = max(ans, l)

print(ans)