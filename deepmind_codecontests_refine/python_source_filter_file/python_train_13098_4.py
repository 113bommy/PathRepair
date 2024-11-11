from heapq import *

n,m,s,t=map(int,input().split())
s-=1
t-=1
INF=float("inf")
Gyen=[[]for i in range(n)]
Gsnu=[[]for i in range(n)]
for i in range(m):
  u,v,a,b=map(int,input().split())
  u-=1
  v-=1
  Gyen[u].append([v,a])
  Gyen[v].append([u,a])
  Gsnu[u].append([v,b])
  Gsnu[v].append([u,b])

def dijkstra(G,s):
  d=[INF]*n
  d[s]=0
  visited={s}
  que=[[0,s]]
  while(que):
    p=heappop(que)
    v=p[1]
    visited.add(v)
    for node,cost in G[v]:
      if (node not in visited) and d[node]>d[v]+cost:
        d[node]=d[v]+cost
        heappush(que,[d[node],node])
  return d

yen=dijkstra(Gyen,s)
snu=dijkstra(Gsnu,t)
ans=10**15
ans_list=[]
for i in reversed(range(n)):
  ans=min(ans,yen[i]+snu[i])
  ans_list.append(10**15-ans)
print(*ans_list[::-1], sep='\n')
