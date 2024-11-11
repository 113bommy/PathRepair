import sys
input = sys.stdin.readline
from collections import defaultdict, deque

n, m = map(int, input().split())
G = defaultdict(set)
U = 10**6
seen = set()
for _ in range(m):
  p, q, c = map(int, input().split())
  G[p+U*c].add((q+U*c, 0))
  G[q+U*c].add((p+U*c, 0))
  G[p+U*c].add((p-U, 0))
  G[q+U*c].add((q-U, 0))
  G[p-U].add((p+U*c, 1))
  G[q-U].add((q+U*c, 1))
que = deque()
que.append((1-U, 0))
while que:
  v, cnt = que.popleft()
  if v in seen:
    continue
  if v == n-U:
    print(cnt)
    exit()
  seen.add(v)
  for nv, cost in G[v]:
    if cost == 0:
      que.appendleft((nv, cnt+cost))
    else:
      que.append((nv, cnt+cost))
print(-1)