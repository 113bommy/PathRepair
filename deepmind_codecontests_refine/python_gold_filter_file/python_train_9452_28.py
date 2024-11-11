def bellman_ford(v, G):
    import copy
    INF = 10 ** 10
    ret = [INF] * len(G)
    ret[v] = 0

    for _ in range(len(G) - 1):
        for u, g in enumerate(G):
            for w, l in g:
                if not ret[u] == INF and ret[w] > ret[u] + l:
                    ret[w] = ret[u] + l

    for _ in range(len(G) - 1):
        for u, g in enumerate(G):
            for w, l in g:
                if not ret[w] == INF and ret[w] > ret[u] + l:
                    ret[w] = -INF

    return ret


N, M, P = map(int, input().split())
G = [[] for _ in range(N)]

for i in range(M):
    A, B, C = map(int, input().split())
    G[A - 1].append((B - 1, - C + P))

ans = bellman_ford(0, G)[-1]
print("-1" if ans == -10 ** 10 else max(-ans, 0))
