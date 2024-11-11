n, d, a = map(int, input().split())
l = [[0, 0] for _ in range(n)]
for i in range(n):
  x, h = map(int, input().split())
  l[i][0] = x
  l[i][1] = h
  
l.sort()
from collections import deque
d = 2*d
q = deque([])
total = 0

ans = 0
for i in range(n):
  x = l[i][0]
  h = l[i][1]
  if q:
    while q[0][0] < x:
      total -= q[0][1]
      q.popleft()
      if not q:
        break
  h -= total
  if h > 0:
    num = (h+a-1)//a
    ans += num
    damage = num*a
    total += damage
    q.append([x+d, damage])

print(ans)