import sys
from collections import deque as dq
input = sys.stdin.readline
for _ in range(int(input())):
  N, a, b, da, db = map(int, input().split())
  e = [[] for _ in range(N + 1)]
  for _ in range(N - 1):
    u, v = map(int, input().split())
    e[u].append(v)
    e[v].append(u)
  if da * 2 + 1 > db:
    print("Alice")
    continue
  Q = dq([a])
  inf = N + 1
  dpa = [inf] * (N + 1)
  dpa[a] = 0 
  while len(Q):
    x = Q.popleft()
    for y in e[x]:
      if dpa[y] > dpa[x] + 1:
        dpa[y] = dpa[x] + 1
        Q.append(y)
  if dpa[b] <= da:
    print("Alice")
    continue
  far = a
  for v in range(1, N + 1):
    if dpa[far] < dpa[v]: far = v
  dp = [inf] * (N + 1)
  dp[far] = 0 
  Q.append(far)
  while len(Q):
    x = Q.popleft()
    for y in e[x]:
      if dp[y] > dp[x] + 1:
        dp[y] = dp[x] + 1
        Q.append(y)
  dia = -(-max(dp[1: ]) // 2)
  if dia <= da:
    print("Alice")
    continue
  print("Bob")