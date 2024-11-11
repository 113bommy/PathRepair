import sys
input=sys.stdin.readline

def BellmanFord(Edges,num_v,source):
    inf=float('inf')
    dist=[inf for _ in range(num_v)]
    dist[source]=0
    for i in range(num_v):
        for edge in Edges:
            if edge[0]!=inf and dist[edge[1]]>dist[edge[0]]+edge[2]:
                dist[edge[1]]=dist[edge[0]]+edge[2]
                if i==num_v-1:
                    before_dist=dist[num_v-1]
                    for _ in range(num_v):
                        for edge in Edges:
                            if edge[0]!=inf and dist[edge[1]]>dist[edge[0]]+edge[2]:
                                dist[edge[1]]=dist[edge[0]]+edge[2]
                    if before_dist!=dist[num_v-1]:
                        return -1
    return dist

n,m,p=map(int,input().split())
Edges=[]
for _ in range(m):
    a,b,c=map(int,input().split())
    a-=1; b-=1
    Edges.append((a,b,-(c-p)))
d=BellmanFord(Edges,n,0)
print(-1 if d==-1 else max(0,-d[-1]))