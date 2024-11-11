import heapq


class Edge():

    def __init__(self, _to, _cost):
        self.to = _to
        self.cost = _cost


class Dijkstra():
    def __init__(self, V):

        self.G = [[] for i in range(V+1)]
        self._E = 0
        self._V = V

    @property
    def E(self):
        """ 辺数 """
        return self._E

    @property
    def V(self):
        """ 頂点数 """
        return self._V

    def add(self, _from, _to, _cost):
        self.G[_from].append(Edge(_to, _cost))
        self._E += 1

    def shortest_path(self, s):

        que = []
        heapq.heapify(que)
        d = [10**10] * (self._V+1)
        par = [-1] * (self._V + 1)
        d[s] = 0
        heapq.heappush(que, (0, s))

        while que:
            cost, v = heapq.heappop(que)
            if d[v] < cost:
                continue

            for e in self.G[v]:
                if d[e.to] > d[v] + e.cost:
                    d[e.to] = d[v] + e.cost
                    par[e.to] = v
                    heapq.heappush(que, (d[e.to], e.to))
        return d, par


N, M = map(int, input().split())
G = []
ans = []
now_dis = 10**6
for i in range(M):
    a, b = map(int, input().split())
    G.append((a, b))
for i in range(M):
    graph = Dijkstra(N)
    for j in range(M):
        if j != i:
            graph.add(G[j][0], G[j][1], 1)
    S, T = G[i][0], G[i][1]
    d, par = graph.shortest_path(T)
    if d[S]+1 < now_dis:
        now_dis = d[S]+1
        sub = []
        node = S
        while node != T:
            sub.append(node)
            node = par[node]
        sub.append(T)
        ans = sub

K=len(ans)
if K==0:
    print(-1)
    exit()
print(K)
for x in ans:
    print(x)