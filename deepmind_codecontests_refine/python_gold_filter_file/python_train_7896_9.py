import heapq

INF = 1000000000


def dijkstra(G, d, s):
    h = []
    d[s] = 0
    heapq.heappush(h, (0, s))

    while len(h) != 0:
        p = heapq.heappop(h)
        v = p[1]
        if d[v] < p[0]:
            continue
        for e in G[v]:
            if d[e[0]] > d[v] + e[1]:
                d[e[0]] = d[v] + e[1]
                heapq.heappush(h, (d[e[0]], e[0]))


def main():
    N, M = map(int, input().split())
    p = [0] * M
    q = [0] * M
    c = [0] * M
    for i in range(M):
        p[i], q[i], c[i] = map(int, input().split())
        p[i] -= 1
        q[i] -= 1
    plat = []
    for i in range(N):
        plat.append(dict())
    v_count = 0
    for i in range(M):
        p1 = plat[p[i]]
        if not c[i] in p1:
            p1[c[i]] = v_count
            v_count += 1
        p2 = plat[q[i]]
        if not c[i] in p2:
            p2[c[i]] = v_count
            v_count += 1
    for i in range(N):
        plat[i][-1] = v_count
        v_count += 1

    G = [[] for _ in range(v_count)]
    for i in range(M):
        p1 = plat[p[i]][c[i]]
        q1 = plat[q[i]][c[i]]
        G[p1].append((q1, 0))
        G[q1].append((p1, 0))
    for i in range(N):
        out = plat[i][-1]
        for v in plat[i].values():
            if v == -1:
                continue
            G[v].append((out, 0))
            G[out].append((v, 1))

    start = plat[0][-1]
    goal = plat[N - 1][-1]

    d = [INF for _ in range(v_count)]

    dijkstra(G, d, start)

    if d[goal] == INF:
        print(-1)
    else:
        print(d[goal])


if __name__ == '__main__':
    main()
