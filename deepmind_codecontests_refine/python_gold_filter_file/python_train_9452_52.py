N, M, P = map(int, input().split())
edges = []
for i in range(M):
    A, B, C = map(int, input().split())
    edges.append([A, B, P - C])


def BellmanFord(edges, num_v, source):
    minus_flag = 0
    inf_flag = 0
    # グラフの初期化
    inf = float("inf")
    dist = [inf for i in range(num_v)]
    dist[source - 1] = 0

    # 辺の緩和
    for i in range(num_v * 3):
        for edge in edges:
            if edge[0] != inf and dist[edge[1] - 1] > dist[edge[0] - 1] + edge[2]:
                dist[edge[1] - 1] = dist[edge[0] - 1] + edge[2]
                if i == num_v - 1:
                    minus_flag = 1
                if minus_flag == 1:
                    if edge[1] == N:
                        inf_flag = 1

    if inf_flag == 0:
        return dist
    else:
        dist.append(-1)
        return dist


ans = BellmanFord(edges, N, 1)
if len(ans) != N:
    print(-1)
else:
    print(max(0, ans[-1] * -1))
