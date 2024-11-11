def bfs(adj, s):
    n = len(adj)
    d = [-1 for _ in range(n)]
    c = [0 for _ in range(n)]

    d[s] = 0
    c[s] = 1

    queue = [s]

    while len(queue) > 0:
        u = queue.pop(0)
        for v in adj[u]:
            if c[v] == 0:
                c[v] = 1
                d[v] = d[u] + 1
                queue.append(v)

    return d


n = int(input())
adj = [[] for _ in range(n)]
for _ in range(n):
    s = [int(x) for x in input().split()]
    u = s[0]
    for v in s[2:]:
        adj[u - 1].append(v - 1)

d = bfs(adj, 0)

for i in range(n):
    print(str(i + 1) + " " + str(d[i]))
