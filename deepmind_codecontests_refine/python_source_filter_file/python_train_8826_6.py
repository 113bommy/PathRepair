import sys
from collections import Counter
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
c = Counter()
for x in a: c[x] += 1
cv = Counter()
for v in c.values(): cv[v] += 1
print(cv)

def check(x, K):
  t = 0
  for k, v in cv.items(): t += min(k, x) * v
  return t >= K * x

res = [N] * (N + 1)
for K in range(1, N):
  ok = 0
  ng = res[K] + 1
  while ng - ok > 1:
    m = (ok + ng) // 2
    if check(m, K + 1): ok = m
    else: ng = m
  res[K + 1] = ok

for r in res[1: ]: print(r)