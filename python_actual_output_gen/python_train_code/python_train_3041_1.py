N, M = map(int, input().split())
G = [[] for _ in range(N)]
in_G = [0] * N

for i in range(M):
    x, y = map(int, input().split())
    G[x-1].append(y-1)
    in_G[y-1] += 1

dist = [0] * N
q = [x for x in range(N) if in_G[x] == 0]

while q:
    v = q.pop

    for g in G[v]:
        dist[g] = max(dist[g], dist[v] + 1)
        in_G[g] -= 1
        if in_G[g] == 0:
            q.append(g)

print(max(dist))