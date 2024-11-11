import sys
import heapq
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

INF = 10**13
N, M = map(int, input().split())
G = [[]for i in range(N)]
for i in range(1, N):
    G[i].append([i-1, 0])

for i in range(M):
    L, R, C = map(int, input().split())
    G[L-1].append([R-1, C])

S = 0

def dijkstra(N, S):
    d = [INF for i in range(N)]

    que = []
    d[S] = 0
    heapq.heappush(que, [0, S])

    while not(len(que) == 0):
        q = heapq.heappop(que)
        ver = q[1] # ノード
        dis = q[0] # 過去に更新された最短距離

        # vまで2番目に短い距離（最新）　＜　過去最短距離　の時、
        # キューから取り出した過去のものを無視する
        if d[ver] < dis:
            continue

        # 隣接リストに対してループ
        for i in range(len(G[ver])):
            e = G[ver][i]
            if d[e[0]] > d[ver] + e[1]:
                d[e[0]] = d[ver] + e[1]
                heapq.heappush(que, [d[e[0]], e[0]])

    return d[N-1]

ans = dijkstra(N, S)
if ans == INF:
    print(-1)
else:
    print(dijkstra(N, S))