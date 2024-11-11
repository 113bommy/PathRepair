from collections import deque
class Dinic:
    def __init__(self, N):
        elf.N = N
        self.G = [[] for i in range(N)]

    def add_edge(self, fr, to, cap):
        forward = [to, cap, None]
        forward[2] = backward = [fr, 0, forward]
        self.G[fr].append(forward)
        self.G[to].append(backward)

    def add_multi_edge(self, v1, v2, cap1, cap2):
        edge1 = [v2, cap1, None]
        edge1[2] = edge2 = [v1, cap2, edge1]
        self.G[v1].append(edge1)
        self.G[v2].append(edge2)

    def bfs(self, s, t):
        self.level = level = [None]*self.N
        deq = deque([s])
        level[s] = 0
        G = self.G
        while deq:
            v = deq.popleft()
            lv = level[v] + 1
            for w, cap, _ in G[v]:
                if cap and level[w] is None:
                    level[w] = lv
                    deq.append(w)
        return level[t] is not None

    def dfs(self, v, t, f):
        if v == t:
            return f
        level = self.level
        for e in self.it[v]:
            w, cap, rev = e
            if cap and level[v] < level[w]:
                d = self.dfs(w, t, min(f, cap))
                if d:
                    e[1] -= d
                    rev[1] += d
                    return d
        return 0

    def flow(self, s, t):
        flow = 0
        INF = 10**9 + 7
        G = self.G
        while self.bfs(s, t):
            *self.it, = map(iter, self.G)
            f = INF
            while f:
                f = self.dfs(s, t, INF)
                flow += f
        return flow



import sys
sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline

n = int(input())
a = list( map(int, input().split()))

score = 0
INF = float('inf')
graph = Dinic(n+2)

for i in range(n):
    if a[i]>0:
        graph.add_edge(i+1,n+1,a[i])
        score += a[i]
    elif a[i]<0:
        graph.add_edge(0,i+1,-a[i])

for i in range(1,n//2+1):
    for j in range(2*i,n+1,i):
        graph.add_edge(i,j,INF)

print(score-graph.flow(0,n+1))

