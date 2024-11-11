import sys
sys.setrecursionlimit(100000)

n = int(input())
tree = [[] for i in range(n + 1)]
for i in range(n - 1):
    a, b, c = map(int, input().split())
    tree[a].append((b, c))
    tree[b].append((a, c))

depth = [0] * (n + 1)
def dfs(v, p, d):
    depth[v] = d
    for to, cost in tree[v]:
        if to != p:
            dfs(to, v, d + cost)

q, k = map(int, input().split())
dfs(k, 0, 0)
xy = [tuple(map(int, input().split())) for i in range(q)]

for x, y in xy:
    print(depth[x] + depth[y])
