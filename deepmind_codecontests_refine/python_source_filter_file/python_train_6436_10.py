n,m = map(int, input().split())
x = [tuple(map(int, input().split())) for _ in range(n)]
from itertools import *
res = 0
for a in product([-1, 1], [-1, 1], [-1, 1]):
  res = max(res, sum(sorted(((sum(i*j for i,j in zip(a,t)) for t in x),reverse=True)[:m]))
print(res)