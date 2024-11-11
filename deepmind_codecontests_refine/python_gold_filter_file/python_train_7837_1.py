from collections import deque
class Dinic:
    def __init__(self, N):
        self.N = N
        self.G = [[] for i in range(N)]

    # 1方向
    def add_edge(self, fr, to, cap):
        forward = [to, cap, None]
        forward[2] = backward = [fr, 0, forward]
        self.G[fr].append(forward)
        self.G[to].append(backward)

    # 両方向
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
input = sys.stdin.readline

n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

# s:n+1,g:0
f = Dinic(n+2)
INF = 10**15

for i in range(n):
    if b[i] > 0:
        f.add_edge(n+1,i+1,b[i])
    elif b[i] < 0:
        f.add_edge(i+1,0,-b[i])

for i in range(n):
    used = [False]*101
    for j in reversed(range(i)):
        if a[i] % a[j] == 0 and not used[a[j]]:
            f.add_edge(i+1,j+1,INF)
            used[a[j]] = True

ans = sum(b[i]*(b[i] > 0) for i in range(n)) - f.flow(n+1,0)
print(ans)