import sys
from functools import lru_cache

sys.setrecursionlimit(1000000)


@lru_cache(maxsize=None)
def dfs(v):
    lv = links[v]
    return max(map(dfs, lv)) + 1 if lv else 0


n, m = map(int, input().split())
sss = set(range(n))
links = [set() for _ in range(n)]
for line in sys.stdin.readlines():
    x, y = map(int, line.split())
    x -= 1
    y -= 1
    sss.discard(y)
    links[x].add(y)

print(max(map(dfs, sss)))
