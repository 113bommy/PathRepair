import sys
readline = sys.stdin.readline
import collections
class Dinic:
    def __init__(self, vnum):
        self.edge = [[] for i in range(vnum)]
        self.n = vnum
        # infはint型の方が良いかもね
        self.inf = float('inf')
    def addedge(self, st, en, c):
        self.edge[st].append([en, c, len(self.edge[en])])
        self.edge[en].append([st, 0, len(self.edge[st])-1])
    def bfs(self, vst):
        dist = [-1]*self.n
        dist[vst] = 0
        Q = collections.deque([vst])
        while Q:
            nv = Q.popleft()
            for vt, c, r in self.edge[nv]:
                if dist[vt] == -1 and c > 0:
                    dist[vt] = dist[nv] + 1
                    Q.append(vt)
        self.dist = dist
    def dfs(self, nv, en, nf):
        nextv = self.nextv
        if nv == en:
            return nf
        dist = self.dist
        ist = nextv[nv]
        for i, (vt, c, r) in enumerate(self.edge[nv][ist:], ist):
            if dist[nv] < dist[vt] and c > 0:
                df = self.dfs(vt, en, min(nf, c))
                if df > 0:
                    self.edge[nv][i][1] -= df
                    self.edge[vt][r][1] += df
                    return df
            nextv[nv] += 1
        return 0
    def getmf(self, st, en):
        mf = 0
        while True:
            self.bfs(st)
            if self.dist[en] == -1:
                break
            self.nextv = [0]*self.n
            while True:
                fl = self.dfs(st, en, self.inf)
                if fl > 0:
                    mf += fl
                else:
                    break
        return mf


N, M = map(int, readline().split())

G = [[1 if s == '#' else 0 for s in readline().strip()] for _ in range(N)]

T = Dinic(2*N*M+2)
st = 2*N*M
en = st+1
geta = N*M
DIREC = ((1, 0), (-1, 0), (0, 1), (0, -1))


for i in range(N):
    for j in range(M):
        if not G[i][j]:
            if (i+j)%2:
                T.addedge(st, i*N+j, 1)
                for di, dj in DIREC:
                    ni, nj = i+di, j+dj
                    if 0 <= ni < N and 0 <= nj < M and not G[ni][nj]:
                        T.addedge(i*N+j, geta + ni*N+nj, 1)
            else:
                T.addedge(geta + i*N+j, en, 1)

print(T.getmf(st, en))

Ans = [g[:] for g in G]

for i in range(N):
    for j in range(M):
        if not (i+j)%2 and not G[i][j]:
            for vf, c, _ in T.edge[geta + N*i+j]:
                if c == 1 and vf != en:
                    ni, nj = divmod(vf, N)
                    if i == ni:
                        if j < nj:
                            Ans[i][j] = 2
                            Ans[ni][nj] = 3
                        else:
                            Ans[i][j] = 3
                            Ans[ni][nj] = 2
                    else:
                        if i < ni:
                            Ans[i][j] = 4
                            Ans[ni][nj] = 5
                        else:
                            Ans[i][j] = 5
                            Ans[ni][nj] = 4

D = ['.', '#', '>', '<', 'v', '^']

print('\n'.join(''.join(D[ai] for ai in a) for a in Ans))      