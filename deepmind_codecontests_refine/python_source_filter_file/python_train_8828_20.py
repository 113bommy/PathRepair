from collections import defaultdict

n,m=map(int,input().split())
adj=defaultdict(list)
deg=[0]*(n+1)
for i in range(m):
    x,y=map(int,input().split())
    adj[x].append(y)
    deg[y]+=1

dist=[0]*(n+1)

que=[]
for i in range(n+1):
    if deg[i]==0:
        que.append(i)

while que:
    v=que.pop()
    for i in adj[v]:
        deg[i]-=1
        if deg[i]==0:
            que.append(i)
            dist[i]=max(dist[i],dist[v]+1)

print(max(dist))
 
