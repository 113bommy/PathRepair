INF=10**30
def Belman_Ford(s,N,Edge):
    dist=[INF]*N
    neg=[False]*N
    dist[s]=0
    for i in range(N-1):
        for f,t,c in Edge:
            if dist[t]>dist[f]+c and dist[f]!=INF:
                dist[t]=min(dist[t],dist[f]+c)
    for i in range(N):
        for f,t,c in Edge:
            if dist[t]>dist[f]+c and dist[f]!=INF:
                dist[t]=dist[f]+c
                neg[t]=True
            if neg[f]:
                neg[t]=True
    return dist,neg
                
N,M,P=map(int,input().split())
Edge=[]
for i in range(M):
    a,b,c=map(int,input().split())
    Edge.append((a-1,b-1,-(c-P)))
dist,neg=Belman_Ford(0,N,Edge)

if(neg[N-1]):
    print(-1)
else:
    ans=-dist[N-1]
    print(max(0,ans))