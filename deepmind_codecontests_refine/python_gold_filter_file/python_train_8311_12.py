import sys
from functools import lru_cache
sys.setrecursionlimit(1000000)
input=sys.stdin.readline


N = int(input())
par = {i:[] for i in range(1, N+1)}

for i in range(2, N+1):
    a = int(input())
    par[a].append(i)

@lru_cache(maxsize=None)
def dfs(s):
    depth = 1
    res = []
    for t in par[s]:
        res.append(dfs(t))
    res.sort(reverse=True)
    for i, j in enumerate(res, start=1):
        depth = max(depth, i+j)
    return depth

print(dfs(1)-1)