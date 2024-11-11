n, m, s, t = map(int, input().split())
G = [[] for i in range(n + 1)]
for i in range(m):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)


def bfs(x, d):
    q = [x]
    while q:
        c = q.pop()
        for y in G[c]:
            if not d[y]:
                d[y] = d[c] + 1
                q.append(y)
                # q.insert(0, y)
    d[x] = 0


ds = [0 for i in range(n + 1)]
dt = [0 for i in range(n + 1)]

bfs(s, ds)
bfs(t, dt)

D = ds[t]
pairs = 0

for u in range(1, n + 1):
    for v in range(u + 1, n + 1):
        if u in G[v]:
            continue

        min_long = min(ds[u] + dt[v] + 1, ds[v] + dt[u] + 1)
        if min_long >= D:
            pairs += 1

print(pairs)
