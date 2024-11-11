def dijkstra(v, G):
    import heapq

    ret = [10 ** 10] * len(G)
    ret[v] = 0
    q = [(ret[i], i) for i in range(len(G))]
    heapq.heapify(q)

    while len(q):
        tmpr, u = heapq.heappop(q)
        if tmpr == ret[u]:
            for w, l in G[u]:
                if ret[w] > ret[u] + l:
                    ret[w] = ret[u] + l
                    heapq.heappush(q, (ret[w], w))
    return ret


N, M, S = map(int, input().split())
UVAB = [tuple(map(int, input().split())) for _ in range(M)]
CD = [tuple(map(int, input().split())) for _ in range(N)]

maxA = max([a for u, v, a, b in UVAB])
Q = maxA * (N - 1) + 1
G = [[] for _ in range(Q * N)]

for u, v, a, b in UVAB:
    for q in range(Q):
        if q >= a:
            G[Q * (u - 1) + q].append((Q * (v - 1) + q - a, b))
            G[Q * (v - 1) + q].append((Q * (u - 1) + q - a, b))

for n, (c, d) in enumerate(CD):
    for q in range(Q):
        G[Q * n + q].append((Q * n + min(Q - 1, c + q), d))

ans = dijkstra(min(S, Q - 1), G)
for n in range(1, N):
    print(min(ans[Q * n:Q * (n + 1)]))
