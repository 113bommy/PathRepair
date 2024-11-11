from collections import deque; import sys; input = sys.stdin.readline

def bfs(s):
    queue = deque([s])
    cv = [0] * n
    cv[s] = 1
    par = [-1] * n
    while queue:
        u = queue.popleft()
        col = 1 + int(par[u] == 1)
        for nxt in adj[u]:
            if not cv[nxt]:
                if u in bad:
                    if (u, nxt) in d_edges:
                        d_edges[(u, nxt)] = 1
                    else:
                        d_edges[(nxt, u)] = 1
                    par[nxt] = 1
                else:
                    if (u, nxt) in d_edges:
                        d_edges[(u, nxt)] = col
                    else:
                        d_edges[(nxt, u)] = col
                    par[nxt] = col
                    col += 1
                    if col == par[u]:
                        continue
                queue.append(nxt)
                cv[nxt] = 1

n, k = [int(item) for item in input().split()]
adj = {}
edges = []
for i in range(n - 1):
    u, v = [int(item) - 1 for item in input().split()]
    edges.append((u, v))
    for j in range(2):
        if u in adj: adj[u].append(v)
        else: adj[u] = [v]
        u, v = v, u

d_edges = {edge: 0 for edge in edges}
p = sorted([(i, len(adj[i])) for i in range(n)], key = lambda p:(p[1], p[0]), reverse=True)
r = p[k][1]
print(r)
bad = set(p[i][0] for i in range(k))
bfs(0)
print(*[d_edges[edge] for edge in edges])
