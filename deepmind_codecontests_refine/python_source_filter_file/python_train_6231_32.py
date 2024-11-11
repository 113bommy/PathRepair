import math

INF = float("inf")

V, E = map(int, input().split())
es = []

for _ in range(E):
    a, b, c = map(int, input().split())
    es.append([a-1, b-1, -c])

d = [INF] * V
d[0] = 0
cnt = [0] * V

for _ in range(V):
    updated = False
    for e in es:
        if math.isinf(d[e[0]]):
            continue
        if d[e[1]] > d[e[0]] + e[2]:
            d[e[1]] = d[e[0]] + e[2]
            cnt[e[1]] += 1
            updated = True
    if not updated:
        break

print(-d[V-1] if cnt[V-1] < V-1 else "inf")
