import sys
input = sys.stdin.readline
from collections import defaultdict
from heapq import heappop, heappush

class Graph(object):

    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, a, b, w):
        self.graph[a].append((b, w))


class Dijkstra(object):
    def __init__(self, graph, s):
        self.g = graph.graph
        self.dist = defaultdict(lambda: float('inf'))
        self.dist[s] = 0

        self.Q = []
        heappush(self.Q, (self.dist[s], s))
        while self.Q:
            dist_u, u = heappop(self.Q)
            if self.dist[u] < dist_u:
                continue
            for v, w in self.g[u]:
                alt = dist_u + w
                if self.dist[v] > alt:
                    self.dist[v] = alt
                    heappush(self.Q, (alt, v))

    def s_d(self, goal):
        return self.dist[goal]


xs, ys, xg, yg = list(map(int, input().split()))
xyr = []
xyr.append([xs, ys, 0])
N = int(input())

for i in range(N):
    xyr.append(list(map(int, input().split())))
xyr.append([xg, yg, 0])

g_a = Graph()
for i in range(N + 1):
    for j in range(i + 1, N + 2):
        R = ((xyr[i][0] - xyr[j][0]) * (xyr[i][0] - xyr[j][0]) + (xyr[i][1] - xyr[j][1]) * (xyr[i][1] - xyr[j][1]))
        R = R ** 0.5
        if R > xyr[i][2] + xyr[j][2]:
            r = R - xyr[i][2] - xyr[j][2]
        else:
            r = 0
        g_a.add_edge(i, j, r)
        g_a.add_edge(j, i, r)

d_a = Dijkstra(g_a, 0)
print(d_a.s_d(N + 1))