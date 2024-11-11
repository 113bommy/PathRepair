INF = 10**18
n, m, p = [int(item) for item in input().split()]
edge = [[] for _ in range(n)]
for i in range(m):
    a, b, c = [int(item) for item in input().split()]
    a -= 1; b -= 1; c -= p
    c *= -1
    edge[a].append((b, c))
 
dist = [INF] * n
dist[0] = 0
update = 1
terminal_update = 0
for _ in range(n):
    update = 0
    for v, e in enumerate(edge):
        for t, cost in e:
            if dist[v] != INF and dist[v] + cost < dist[t]:
                dist[t] = dist[v] + cost
                update = 1
                if t == n-1:
                    terminal_update += 1
    if not update:
        print(max(0, -dist[n-1]))
        exit()
else:
    if terminal_update > 1:
        print(-1)
    else:
        print(max(0, -dist[n-1]))