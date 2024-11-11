import sys
from collections import defaultdict as dd
from bisect import bisect_left as bl
input = sys.stdin.readline
N = int(input())
a = [0] + list(map(int, input().split()))
e = dd(list)
for _ in range(N - 1):
  u, v = map(int, input().split())
  e[u].append(v)
  e[v].append(u)

inf = 10 ** 6
lis = [inf] * (N * 2)
s = [1]
vis = [0] * (N + 1)
euler = []
while len(s):
  x = s.pop()
  if x >= 0:
    vis[x] = 1
    euler.append(x)
    for y in e[x]:
      if vis[y]: continue
      s.append(~y)
      s.append(y)
  else: euler.append(x)

rollback = []
res = [0] * (N + 1)
for x in euler:
  if x >= 0:
    y = bl(lis, a[x])
    rollback.append((y, lis[y]))
    lis[y] = a[x]
    res[x] = bl(lis, inf)
  else:
    y, v = rollback.pop()
    lis[y] = v

for r in res[1: ]: print(r)