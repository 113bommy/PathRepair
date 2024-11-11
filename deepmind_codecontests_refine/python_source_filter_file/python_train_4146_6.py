from collections import defaultdict
import math
N = int(input())
A = [int(x) for x in input().split()]
D = defaultdict(int)
for a in A:
  D[a] += 1
cnt = 0
for a in sorted(D.keys(), reverse=True):
  p = 2 ** math.ceil(math.log(a, 2))
  d = p - a
  if a == d:
    cnt += D[a] // 2
    D[a] %= 2
  else:
    m = min(D[a], D[d])
    cnt += m
    D[a] -= m
    D[d] -= m
print(cnt)