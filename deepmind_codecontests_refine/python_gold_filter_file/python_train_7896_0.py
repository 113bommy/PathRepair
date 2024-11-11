import sys
readline = sys.stdin.readline

from heapq import heappop as hpp, heappush as hp
inf = 10**9+7
def dijkstra(N, s, Edge):    
    dist = [inf] * N
    dist[s] = 0
    Q = [(0, s)]
    while Q:
        dn, vn = hpp(Q)
        if dn > dist[vn]:
            continue
        for df, vf in Edge[vn]:
            if dn + df < dist[vf]:
                dist[vf] = dn + df
                hp(Q, (dn + df,vf))
    return dist

def compress(L):
    L2 = list(set(L))
    L2.sort()
    C = {v : k for k, v in enumerate(L2)}
    return L2, C


N, M = map(int, readline().split())

Edge = []
VS = set(range(N))
geta = 20
Edge = [tuple(map(int, readline().split())) for _ in range(M)]
for a, b, c in Edge:
    a -= 1
    b -= 1
    VS |= {(c<<geta) | a, (c<<geta) | b}
   
_, Cv = compress(list(VS))

Vnum = len(Cv)

nEdge = [[] for _ in range(Vnum)]

for a, b, c in Edge:
    a -= 1
    b -= 1
    ca = Cv[(c<<geta) | a]
    cb = Cv[(c<<geta) | b]
    nEdge[ca].append((0, cb))
    nEdge[cb].append((0, ca))
    nEdge[a].append((1, ca))
    nEdge[ca].append((0, a))
    nEdge[b].append((1, cb))
    nEdge[cb].append((0, b))

dist = dijkstra(Vnum, 0, nEdge)
if dist[N-1] >= inf:
    dist[N-1] = -1
print(dist[N-1])  