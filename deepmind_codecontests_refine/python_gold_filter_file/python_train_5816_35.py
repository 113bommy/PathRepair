# Cosmic rays
import math
import heapq

xs, ys, xt, yt = map(int, input().split())
N = int(input())

d = [((xs, ys), 0, 0)]
# node,radius

for _ in range(N):
    x, y, r = map(int, input().split())
    d.append(((x, y), _+1, r))

graph = {i: [] for i in range(N+2)}

d.append(((xt, yt), N+1, 0))
for i in range(N+2):
    for j in range(i+1, N+2):
        p, point, rad = d[i]
        q, point2, rad2 = d[j]
        D = math.hypot(p[0]-q[0], p[1]-q[1])
        if D > (rad+rad2):
            graph[i].append((D-rad-rad2, j))
            graph[j].append((D-rad-rad2, i))
        else:
            graph[i].append((0, j))
            graph[j].append((0, i))


def dijkstra(s, graph):
    n = len(graph)
    dist = [float("inf") for i in range(n+1)]
    dist[s] = 0
    pq = []
    heapq.heapify(pq)
    heapq.heappush(pq, (0, s))
    while pq:
        mini_dis, node = heapq.heappop(pq)
        if dist[node] < mini_dis:
            continue
        for w, point in graph[node]:
            if dist[point] < w:
                continue
            newlen = dist[node]+w
            if newlen < dist[point]:
                heapq.heappush(pq, (newlen, point))
                dist[point] = newlen
    return dist

K=dijkstra(0,graph)[N+1]
print(K)
