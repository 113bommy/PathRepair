# 解説AC、辺の張り方が難しすぎる
from collections import deque
INF = 1 << 23


class Dinic:
    def __init__(self, N):
        self.N = N
        self.G = [[] for _ in range(self.N)]

    def add_edge(self, u, v, cap):
        self.G[u].append([v, cap, len(self.G[v])])
        self.G[v].append([u, 0, len(self.G[u])-1])

    def bfs(self, s):
        self.level = [-1] * self.N
        que = deque([s])
        self.level[s] = 0
        while que:
            u = que.popleft()
            for (v, cap, _) in self.G[u]:
                if cap > 0 and self.level[v] < 0:
                    self.level[v] = self.level[u] + 1
                    que.append(v)

    def dfs(self, u, t, f):
        if u == t:
            return f
        for i in range(self.progress[u], len(self.G[u])):
            self.progress[u] = i
            (v, cap, rev) = self.G[u][i]
            if cap > 0 and self.level[u] < self.level[v]:
                d = self.dfs(v, t, min(f, cap))
                if d > 0:
                    self.G[u][i][1] -= d
                    self.G[v][rev][1] += d
                    return d
        return 0

    def max_flow(self, s, t):
        flow = 0
        INF = 10**9
        while True:
            self.bfs(s)
            if self.level[t] < 0:
                return flow
            self.progress = [0] * self.N
            current_flow = self.dfs(s, t, INF)
            while current_flow > 0:
                flow += current_flow
                current_flow = self.dfs(s, t, INF)


def main():
    H, W = (int(i) for i in input().split())
    A = [input() for i in range(H)]
    F = Dinic(H+W+2)  # 0,1,...,H-1,W,..,W-1,s,t
    s = H+W
    t = H+W+1
    Sh, Sw = -1, -1
    Th, Tw = -1, -1
    for h in range(H):
        for w in range(W):
            if A[h][w] == "S":
                Sh, Sw = h, w
                F.add_edge(s, h, INF)
                F.add_edge(s, w, INF)
            elif A[h][w] == "T":
                Th, Tw = h, w
                F.add_edge(h, t, INF)
                F.add_edge(w, t, INF)
            if A[h][w] != ".":
                F.add_edge(h+W, w, 1)
                F.add_edge(w, h+W, 1)
    if Sh == Th or Sw == Tw:
        return print(-1)

    print(F.max_flow(s, t))


if __name__ == '__main__':
    main()
