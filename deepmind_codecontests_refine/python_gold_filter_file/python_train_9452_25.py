import sys
input=sys.stdin.readline

def BellmanFord(Edges,num_v,start,goal):
    inf=float('inf')
    Dist=[inf]*num_v
    Dist[start]=0
    for _ in range(num_v):
        for fr,to,cost in Edges:
            if Dist[fr]!=inf and Dist[to]>Dist[fr]+cost:
                Dist[to]=Dist[fr]+cost
    d=Dist[goal]
    for _ in range(num_v):
        for fr,to,cost in Edges:
            if Dist[fr]!=inf and Dist[to]>Dist[fr]+cost:
                Dist[to]=-inf
    if d!=Dist[goal]:
        return -inf
    return d

n,m,p=map(int,input().split())
Edges=[]
for _ in range(m):
    a,b,c=map(int,input().split())
    a-=1; b-=1
    Edges.append((a,b,-(c-p)))
d=BellmanFord(Edges,n,0,n-1)
print(-1 if d==-float('inf') else max(0,-d))