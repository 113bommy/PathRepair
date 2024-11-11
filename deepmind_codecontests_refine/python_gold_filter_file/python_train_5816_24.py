import math
import heapq
xs,ys,xt,yt=map(int,input().split())
N=int(input())
x=[xs]+[0 for i in range(N)]+[xt]
y=[ys]+[0 for i in range(N)]+[yt]
r=[0]+[0 for i in range(N)]+[0]
for i in range(1,N+1):
    x[i],y[i],r[i]=map(int,input().split())
dist=[10**15 for i in range(N+2)]
dist[0]=0
adjlist=[[0 for i in range(N+2)] for j in range(N+2)]
for i in range(N+2):
    for j in range(N+2):
        if i==j:
            continue
        adjlist[i][j]=max(math.sqrt((x[i]-x[j])**2+(y[i]-y[j])**2)-r[i]-r[j],0)
q=[]
heapq.heappush(q,(0,0))
while(len(q)>0):
    d,p=heapq.heappop(q)
    if dist[p]<d:
        continue
    for j in range(N+2):
        if p==j:
            continue
        cost=adjlist[p][j]
        if dist[j]>dist[p]+cost:
            dist[j]=dist[p]+cost
            heapq.heappush(q,(dist[j],j))
print(dist[N+1])