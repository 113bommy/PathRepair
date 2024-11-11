from collections import defaultdict
from heapq import heappop, heappush


class Graph(object):

    def __init__(self):
        self.graph = defaultdict(list)

    def __len__(self):
        return len(self.graph)

    def add_edge(self, From, To, cost=1):
        self.graph[From].append((To,cost))

    def get_nodes(self):
        return self.graph.keys()
class Dijkstra(object):

    def __init__(self, graph, start):
        self.g = graph.graph
        self.dist = defaultdict(lambda:float('inf'))
        self.dist[start] = 0
        self.prev = defaultdict(lambda: None)
        self.Q = []
        heappush(self.Q,(self.dist[start], start))

        while  self.Q:
            dist_u, u = heappop(self.Q)
            if self.dist[u] < dist_u:
                continue
            for v, cost in self.g[u]:
                alt = dist_u + cost
                if self.dist[v] > alt:
                    self.dist[v] = alt
                    self.prev[v] = u
                    heappush(self.Q,(alt, v))

    def shortest_distance(self, goal):
        return self.dist[goal]

    def shortest_path(self, goal):
        path = []
        node = goal
        while node is not None:
            path.append(node)
            node = self.prev[node]

        return path[::-1]


N = int(input())
g = Graph()
d = {}
for i in range(N-1):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    d[(min(a,b),max(a,b))] = i
    g.add_edge(a,b)
    g.add_edge(b,a)

M = int(input())
l = [0]*M
for i in range(M):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    dij = Dijkstra(g,u)
    path = dij.shortest_path(v)
    for j in range(len(path)-1):
        a,b = path[j],path[j+1]
        l[i] += 2**d[(min(a,b),max(a,b))]

c = [0]*(M+1)
p2 = [2**i for i in range(N)]
for n in range(2**M):
    cnt = 0
    x = 0
    for i in range(M):
        if n&2**p2[i]==p2[i]:
            cnt += 1
            x |= l[i]
    y = 0
    for i in range(N-1):
        if x&p2[i]==p2[i]:
            y += 1
    c[cnt] += p2[N-1-y]

ans = 0
for i in range(M+1):
    if i%2==0:
        ans += c[i]
    else:
        ans -= c[i]

print(ans)
