from heapq import heappush, heappop
sx,sy,gx,gy=map(int,input().split())
n=int(input())
g = [[] for i in range(n+2)]
data=[(sx+sy*1j,0)]
for i in range(n):
    a,b,c=map(int,input().split())
    data.append((a+b*1j,c))
data.append((gx+gy*1j,0))

for i in range(n+2):
    for j in range(i+1,n+2):
        tmp=abs(data[i][0]-data[j][0])-data[i][1]-data[j][1]
        g[i].append((tmp,j))
        g[j].append((tmp,i))

dist=[2828427127 for i in range(n+2)]
visited=[False for i in range(n+2)]
dist[0]=0
que=[]
heappush(que,(0,0))

while que:
    c,v=heappop(que)
    if visited[v]:
        continue
    visited[v]=True
    for x in g[v]:
        if visited[x[1]]:
            continue
        tmp=x[0]+c if not x[0]<0 else c
        if tmp<dist[x[1]]:
            dist[x[1]]=tmp
            heappush(que,(tmp,x[1]))
print(dist[n+1])
