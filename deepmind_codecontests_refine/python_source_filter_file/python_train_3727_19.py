import sys
from heapq import heappush as hpu
from heapq import heappop as hpo
input = sys.stdin.readline
N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

base = 10 ** 10
sb = [-(b[i] * base + i) for i in range(N) if a[i] != b[i]]
h = []
for t in sb: hpu(h, t)
res = 0
while len(h):
  v = hpo(h)
  i = -v % base
  v = -v // base
  if v < a[i]:
    print(-1)
    exit(0)
  d = v - a[i]
  x = b[i - 1] + b[(i + 1) % N]
  t = d // x
  if t == 0:
    if v == a[i]: continue
    print(-1)
    exit(0)
  b[i] -= x * (t)
  res += t
  hpu(h, -(b[i] * base + i))
print(res)