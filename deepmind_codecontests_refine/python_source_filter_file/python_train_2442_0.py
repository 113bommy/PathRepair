n, k = map(int, input().split())
ra = [[0] * k for _ in range(n)]
for p in range(k):
    for i, v in enumerate(map(int, input().split())):
        v -= 1
        ra[v][p] = i
g = [[] for _ in range(n)]
for u in range(n):
    for v in range(n):
        if all(x < y for x, y in zip(ra[u], ra[v])):
            g[u].append(v)

memo = [-1] * n
def dfs(v):
    if memo[v] != -1:
        return memo[v]
    r = 0
    for u in g[v]:
        r = max(r, dfs(u) + 1)
    memo[v] = r
    return r

print(max(dfs(s) for s in range(n)))
        
