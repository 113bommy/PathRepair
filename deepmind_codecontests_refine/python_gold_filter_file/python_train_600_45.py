n,m = map(int,input().split())
abd = [list(map(int,input().split())) for i in range(m)]
graph = [[] for i in range(n+1)]
for a,b,d in abd:
  graph[a].append((b,d))
for i in range(1,n):
  graph[i+1].append((i,0))
import heapq as hq
dist = [10**18]*(n+1)
dist[1] = 0
q = [(0,1)]
hq.heapify(q)
while q:
  d,x = hq.heappop(q)
  for y,dd in graph[x]:
    if dist[y] > dist[x]+dd:
      dist[y] = dist[x]+dd
      hq.heappush(q,(dist[y],y))
if dist[n] == 10**18:
  print(-1)
else:
  print(dist[n])