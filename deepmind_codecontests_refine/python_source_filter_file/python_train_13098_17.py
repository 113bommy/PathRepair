n, m, s, t = map(int, input().split())
s-=1
t-=1
G = [[] for i in range(n)]
for i in range(m):
    u,v,a,b=map(int,input().split())
    G[u-1].append((v-1,a,b))
    G[v-1].append((u-1,a,b))

V=10**15
ans=[0]*n
from heapq import heappush,heappop
def dijkstra(u,k):
    D=[10**18]*n
    q=[(u,0)]
    D[u]=0
    while q:
        u,d=heappop(q)
        if D[u]<d: continue
        for v ,a ,b in G[u]:
            w=b if k else a
            if d + w < D[v]:
                D[v]=d+w
                heappush(q,(v,d+w))
    return D
D1=dijkstra(s,0)
D2=dijkstra(t,1)
tmp=1e18
for i in reversed(range(n)):
    tmp=min(tmp,D1[i]+D2[i])
    ans[i]=10**15-tmp
print(*ans,sep="\n")

