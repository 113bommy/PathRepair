def bfs(G, s):
    d = {key: -1 for key in G.keys()}
    d[s] = 0
    Q = [s]
    while len(Q) > 0:
        u = Q.pop(0)
        for v in G[u]:
            if d[v] < 0:
                d[v] = d[u] + 1
                Q.append(v)

    return d


if __name__ == '__main__':
    G = {}
    n = int(input())
    for _ in range(n):
        tmp = list(map(int, input().split()))
        u = tmp.pop(0)
        k = tmp.pop(0)
        G[u] = tmp
    d = bfs(G, 1)
    for node in G:
        print('{0} {1}'.format(node, d[node]))