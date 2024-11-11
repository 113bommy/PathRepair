from collections import deque
from sys import exit

h,w=map(int,input().split())
sh,sw=map(lambda s: int(s)-1,input().split())
gh,gw=map(lambda s: int(s)-1,input().split())
s = [input() for _ in range(h)]
d = [[h*w] * w for _ in range(h)]
q = deque()
d[sh][sw] = 0
q.append((sw, sh))
while len(q):
  p = q.popleft()
  if p[2] != d[p[1]][p[0]]:
    continue
  if p[0] == gw and p[1] == gh:
    print(d[gh][gw])
    exit(0)
  for dx in range(-2, 3):
    nx = p[0] + dx
    if nx < 0 or w <= nx:
      continue
    for dy in range(-2, 3):
      ny = p[1] + dy
      c = 0 if abs(dx) + abs(dy) == 1 else 1
      if dx == dy == 0 or ny < 0 or h <= ny or s[ny][nx] == '#' or d[ny][nx] <= d[p[1]][p[0]] + c:
        continue
      d[ny][nx] = d[p[1]][p[0]] + c
      np = (nx, ny, d[ny][nx])
      if c:
        q.append(np)
      else:
        q.appendleft(np)
print(-1)
