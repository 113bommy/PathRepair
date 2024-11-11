def bellmanford(s, n, es):
    # 負の経路の検出
    # n:頂点数, w:辺の数, es[i]: [辺の始点,辺の終点,辺のコスト]
    d = [float("inf")] * n
    neg = [False]*n
    d[s] = 0

    for i in range(n):
        for p, q, r in es:
            if d[p] != float("inf") and d[q] > d[p] + r:
                d[q] = d[p] + r
                if i == n-1:
                    neg[q] = True
    return d, neg


n, w = map(int, input().split())  # n:頂点数　w:辺の数
es = []

for _ in range(w):
    x, y, z = map(int, input().split())
    es.append([x-1, y-1, -z])

d, neg = bellmanford(0, n, es)
if neg[-1]:
    print("inf")
else:
    print(-d[-1])
