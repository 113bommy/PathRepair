import sys


def reverse_search(n, parents):
    q = [n - 1]
    visited = set()
    while q:
        v = q.pop()
        if v in visited:
            continue
        visited.add(v)
        q.extend(u for u in parents[v] if u not in visited)
    return visited


n, m, p = list(map(int, input().split()))
INF = 10 ** 12
links = [set() for _ in range(n)]
parents = [set() for _ in range(n)]
for line in sys.stdin:
    a, b, c = map(int, line.split())
    a -= 1
    b -= 1
    links[a].add((b, p - c))
    parents[b].add(a)
reachable = reverse_search(n, parents)

dist = [INF] * n
dist[0] = 0
for _ in range(len(reachable)):
    updated = False
    for v in reachable:
        d = dist[v]
        if d == INF:
            continue
        for u, c in links[v]:
            if dist[u] > d + c:
                dist[u] = d + c
                updated = True
    if not updated:
        break
else:
    print(-1)
    exit()

print(max(0, -dist[n - 1]))
