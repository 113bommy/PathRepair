#ARC074-F Lotus Leaves
"""
この問題は最小カットに帰着できる。但し、h*wの頂点を持つと間に合わないので、H軸とW軸を独立に考える。
縦H個、横W個の頂点を持つ。
ある座標h,wがoの時、頂点H[h]とW[w]と容量1のネットワークでつなぐ。[sourse,h0,h1,...hH,w0,w1,...wW,sink]
startとgoalを最大流の始点、終点として持つのではなく、それとは別にsourse,sinkの2頂点を作る。
startとsourse,goalとsinkを容量INFでつなぐことにより、より簡単に最小カットを求めることが可能になる。
よって、グラフ長はH*W+2となる。
ネットワーク自体は無向なので、undirectedを使用する。
"""
import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0

from collections import deque
class Dinic():
    def __init__(self, N, source, sink):
        self.N = N
        self.G = [[] for _ in range(N)]
        self.source = source
        self.sink = sink
 
    def add_edge(self, fr, to, cap):
        n1 = len(self.G[fr])
        n2 = len(self.G[to])
        self.G[fr].append([to, cap, n2])
        self.G[to].append([fr, 0, n1]) # 逆辺を cap 0 で追加
        
    def add_edge_undirected(self, fr, to, cap):
        n1 = len(self.G[fr])
        n2 = len(self.G[to])
        self.G[fr].append([to, cap, n2])
        self.G[to].append([fr, cap, n1]) # 逆辺を cap 0 で追加
        
    def bfs(self):
        level = [0] * self.N
        G = self.G; source = self.source; sink = self.sink
        q = deque([source])
        level[source] = 1
        pop = q.popleft; append = q.append
        while q:
            v = pop()
            lv = level[v] + 1
            for to, cap, rev in G[v]:
                if not cap:
                    continue
                if level[to]:
                    continue
                level[to] = lv
                if to == sink:
                    self.level = level
                    return
                append(to)
        self.level = level
        
    def dfs(self,v,f):
        if v == self.sink:
            return f
        G = self.G
        prog = self.progress
        level = self.level
        lv = level[v]
        E = G[v]
        for i in range(prog[v],len(E)):
            to, cap, rev = E[i]
            prog[v] = i
            if not cap:
                continue
            if level[to] <= lv:
                continue
            x = f if f < cap else cap
            ff = self.dfs(to, x)
            if ff:
                E[i][1] -= ff
                G[to][rev][1] += ff
                return ff
        return 0
    
    def max_flow(self):
        INF = 10**18
        flow = 0
        while True:
            self.bfs()
            if not self.level[self.sink]:
                return flow
            self.progress = [0] * self.N
            while True:
                f = self.dfs(self.source, INF)
                if not f:
                    break
                flow += f
        return flow

H,W = map(int,readline().split())
maze = []
for _ in range(H):
    maze += [list(readline().rstrip().decode())]

source = 0
sink = H+W+1
network = Dinic(H+W+2,sourse,sink)
INF = 10**18

for i in range(1,H+1):
    for j,ox in enumerate(maze[i-1],1):
        if ox == "x":
            continue
        elif ox == "o":
            network.add_edge_undirected(i,H+j,1)
        elif ox == "S":
            network.add_edge_undirected(sourse,i,INF)
            network.add_edge_undirected(sourse,H+j,INF)
        elif ox == "T":
            network.add_edge_undirected(i,sink,INF)
            network.add_edge_undirected(H+j,sink,INF)

f = network.max_flow()
if f == INF:
    print(-1)
else:
    print(f)

