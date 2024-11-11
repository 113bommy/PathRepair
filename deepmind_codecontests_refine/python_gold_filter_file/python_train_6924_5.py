n, m = map(int, input().split())
children = [ [] for u in range(n + 1) ]
degree = [ 0 for u in range(n + 1) ]
for i in range(m):
    u, v = map(int, input().split())
    if u > v:
        u, v = v, u
    children[u].append(v)
    degree[u] += 1
    degree[v] += 1

depth = [ 0 for u in range(n + 1) ]
best = degree[1]
for u in range(1, n + 1):
    for v in children[u]:
        depth[v] = max(depth[v], depth[u] + 1)
        best = max(best, (depth[v] + 1) * degree[v])
print(best)
