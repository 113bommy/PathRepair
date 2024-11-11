import sys
from collections import defaultdict as dd
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
d = dd(int)
l = dd(lambda: N + 1)
for i in range(N):
  d[a[i]] += 1
  l[a[i]] = min(l[a[i]], i + 1)

#print(d, l)
ks = sorted(d.keys(), reverse = True)
res = [0] * (N + 1)
for i in range(len(ks) - 1):
  t = ks[i] - ks[i + 1]
  k = ks[i]
  res[l[k]] += d[k] * t
  d[ks[i + 1]] += d[k]
  l[ks[i + 1]] = min(l[ks[i + 1]], l[k])
res[1] += d[ks[-1]] * ks[-1]
for r in res[1: ]: print(r)