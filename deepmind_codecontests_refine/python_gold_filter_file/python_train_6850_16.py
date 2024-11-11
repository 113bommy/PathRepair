import sys
from collections import deque

sys.setrecursionlimit(10000000)

n,m = map(int,input().split())
to=[[] for _ in range(n)]
dist=[[0] *3 for _ in range(100005)]
INF=10**15

for i in range(m):
    a,b=map(int,input().split())
    a-=1;b-=1
    to[a].append(b)

sv,tv=map(int,input().split())
sv-=1;tv-=1

for i in range(n):
    for j in range(3):
        dist[i][j] =INF

q=deque()
q.append((sv,0))
dist[sv][0]=0

while q:
    v,l=q.popleft()
    for u in to[v]:
        nl =(l+1)%3
        if dist[u][nl] != INF: continue
        dist[u][nl] = dist[v][l]+1
        q.append((u,nl))

ans=dist[tv][0]
if ans == INF:ans=-1
else: ans //=3
print(ans)