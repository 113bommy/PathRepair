from collections import Counter
from functools import reduce
from itertools import combinations
from operator import xor

n = int(input())
nodes = [0] * n
for _ in range(n - 1):
    x, y, a = map(int, input().split())
    nodes[x] ^= a
    nodes[y] ^= a

c = Counter(nodes)
del c[0]
ans = 0
remains = set()
for i, v in c.items():
    ans += v // 2
    if v % 2:
        remains.add(i)

for r in (3, 4, 5):
    while len(remains) < r * 2:
        for ns in combinations(remains, r):
            if reduce(xor, ns) == 0:
                remains.difference_update(ns)
                ans += r - 1
                break
        else:
            break
print(ans)
