import sys
import heapq
from collections import defaultdict
input = sys.stdin.readline
inf = 10**18



def dijkstra(repn, start, goal):
    dist = [inf for i in range(N + 1)] # 始点から各頂点までの最短距離を格納する
    
    dist[start] = 0
    q = []                  # プライオリティキュー．各要素は，(startからある頂点vまでの仮の距離, 頂点vのID)からなるタプル
    heapq.heappush(q, (0, start)) # 始点をpush

    while q:
        prov_cost, src = heapq.heappop(q) # pop
        
        # プライオリティキューに格納されている最短距離が，現在計算できている最短距離より大きければ，distの更新をする必要はない
        if dist[src] < prov_cost:
            continue

        # 他の頂点の探索
        for dest in repn[src]:
            cost = repn[src][dest]
            if dist[dest] > dist[src] + cost:
                dist[dest] = dist[src] + cost # distの更新
                heapq.heappush(q, (dist[dest], dest)) # キューに新たな仮の距離の情報をpush
                
    return dist[goal]
        



N, M = map(int, input().split())
repn = [defaultdict(list) for _ in range(N + 1)]
for i in range(2, N + 1):
    repn[i][i - 1] = 0
for _ in range(M):
    l, r, c = map(int, input().split())
    if repn[l][r] == [] or repn[l][r] > c: #つまずきポイントその１
        repn[l][r] = c

d = dijkstra(repn, 1, N)

if d == 10 ** 18:
    print(-1)
else:
    print(d)
