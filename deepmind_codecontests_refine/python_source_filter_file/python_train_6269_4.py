from collections import defaultdict

n, m = [int(s) for s in input().split()]

adj = defaultdict(set)

for _ in range(m):
    u, v = [int(s) for s in input().split()]
    adj[u].add(v)
    adj[v].add(u)

deg1 = set()
for vertex, neighbors in adj.items():
    if len(neighbors) == 1:
        deg1.add(vertex)

ans = 0
while deg1:
    print(">>> adj:", adj)
    print(">>> deg1:", deg1)
    new = set()
    ans += 1
    for u in deg1:
        for v in adj[u]:
            adj[v].discard(u)
        del adj[u]
    for vertex, neighbors in adj.items():
        if len(neighbors) == 1:
            new.add(vertex)
    deg1 = new
print(ans)
