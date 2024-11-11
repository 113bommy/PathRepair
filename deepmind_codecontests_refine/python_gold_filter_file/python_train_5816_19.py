# coding: utf-8
import sys
from heapq import heapify, heappop, heappush

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

# Nの制約が1000,円の中心を飛び石→dijkstra
sx, sy, gx, gy = lr()
N = ir()
XYR = [[sx, sy, 0]] + [lr() for _ in range(N)] + [[gx, gy, 0]]
graph = [[] for _ in range(N+2)]  # 0がstart,N+1がgoal
for i in range(N+2):
    for j in range(i+1, N+2):
        sp = XYR[i]; ep = XYR[j]
        length = max(0, ((sp[0]-ep[0]) ** 2 + (sp[1]-ep[1]) ** 2) ** .5 - sp[2] - ep[2])
        graph[i].append((j, length))
        graph[j].append((i, length))

def dijkstra(start):
    INF = 10 ** 15
    dist = [INF] * (N+2)
    dist[start] = 0
    que = [(0, start)]
    visited = set()
    while que:
        d, prev = heappop(que)
        if dist[prev] < d:
            continue
        for next, l in graph[prev]:
            if next == prev or next in visited:
                continue
            d1 = d + l
            if dist[next] > d1:
                dist[next] = d1
                heappush(que, (d1, next))
        visited.add(prev)
    return dist

dist = dijkstra(0)
answer = dist[N+1]
print(answer)
# 46
