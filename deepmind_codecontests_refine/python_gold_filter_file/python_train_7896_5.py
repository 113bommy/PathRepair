from collections import defaultdict, deque

N, M = map(int, input().split())
D = {}
Edges = []


class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0] * n

    # 検索
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    # 併合
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    # すべての頂点に対して親を検索する
    def all_find(self):
        for n in range(len(self.par)):
            self.find(n)


UF = UnionFind(M)
for i in range(M):
    p, q, c = map(int, input().split())
    p, q = p-1, q-1
    Edges.append((p, q))

    if (p, c) in D:
        UF.union(D[p, c], i)
    D[p, c] = i

    if (q, c) in D:
        UF.union(D[q, c], i)
    D[q, c] = i

UF.all_find()

Firm_Node = defaultdict(set)
for i in range(M):
    p, q = Edges[i]
    Firm_Node[UF.par[i]].add(p)
    Firm_Node[UF.par[i]].add(q)

G = defaultdict(list)
for firm, node in Firm_Node.items():
    for n in node:
        G[n].append(firm + N)
        G[firm + N].append(n)


def dijkstra(x):
    d = {x: 0, N-1: 10**9}
    visited = {x}

    # d, u
    queue = deque([(0, x)])

    while queue:
        u = queue.pop()[1]
        visited.add(u)

        for node in G[u]:
            d.setdefault(node, float('inf'))
            if (node not in visited) and d[node] > d[u] + 1:
                d[node] = d[u] + 1
                if d[N-1] < 10**9:
                    return d
                queue.appendleft([d[u]+1, node])
    return d


dist = dijkstra(0)
print(dist[N-1] // 2 if dist[N-1] < 2*M else -1)
