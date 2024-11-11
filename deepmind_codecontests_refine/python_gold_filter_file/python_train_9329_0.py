import sys
readline = sys.stdin.readline

from heapq import heappop as hpp, heappush as hp
class MinCostFlowwithDijkstra:
    INF = 1<<60
    
    def __init__(self, N):
        self.N = N
        self.Edge = [[] for _ in range(N)]
    
    def add_edge(self, st, en, cap, cost):
        self.Edge[st].append([en, cap, cost, len(self.Edge[en])])
        self.Edge[en].append([st, 0, -cost, len(self.Edge[st])-1])
    
    def get_mf(self, so, si, fl):
        N = self.N
        INF = self.INF
        res = 0
        Pot = [0]*N
        geta = N
        
        
        prv = [None]*N
        prenum = [None]*N
        while fl:
            dist = [INF]*N
            dist[so] = 0
            Q = [so]
            
            while Q:
                cost, vn = divmod(hpp(Q), geta)
                if dist[vn] < cost:
                    continue
                
                for enum in range(len(self.Edge[vn])):
                    vf, cap, cost, _ = self.Edge[vn][enum]
                    cc = dist[vn] + cost - Pot[vn] + Pot[vf]
                    if cap > 0 and dist[vf] > cc:
                        dist[vf] = cc
                        prv[vf] = vn
                        prenum[vf] = enum
                        hp(Q, cc*geta + vf)
            
            if dist[si] == INF:
                return -1
            
            for i in range(N):
                Pot[i] -= dist[i]
            
            cfl = fl
            vf = si
            while vf != so:
                cfl = min(cfl, self.Edge[prv[vf]][prenum[vf]][1])
                vf = prv[vf]
            
            fl -= cfl
            res -= cfl*Pot[si]
            vf = si
            while vf != so:
                e = self.Edge[prv[vf]][prenum[vf]]
                e[1] -= cfl
                self.Edge[vf][e[3]][1] += cfl
                vf = prv[vf]
        return res

N, Q = map(int, readline().split())
T = MinCostFlowwithDijkstra(2*N+2)
geta = N

candi = [set(range(N)) for _ in range(N)]

for _ in range(Q):
    t, l, r, v = map(int, readline().split())
    l -= 1
    r -= 1
    v -= 1
    if t == 1:
        for vn in range(l, r+1):
            for i in range(v-1, -1, -1):
                if i in candi[vn]:
                    candi[vn].remove(i)
    else:
        for vn in range(l, r+1):
            for i in range(v+1, N):
                if i in candi[vn]:
                    candi[vn].remove(i)

if not all(candi):
    print(-1)
else:
    source = 2*N
    sink = 2*N + 1
    for i in range(N):
        T.add_edge(source, i, 1, 0)
        for v in candi[i]:
            T.add_edge(i, geta+v, 1, 0)
        for j in range(N):
            T.add_edge(i+geta, sink, 1, 2*j+1)
    print(T.get_mf(source, sink, N))
    