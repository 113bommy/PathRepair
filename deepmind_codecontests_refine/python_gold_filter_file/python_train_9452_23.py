import sys
inf = 10000000000

def BellmanFord(edges,points,start):#edgeは1-indexedの起点/終点/距離
  #グラフの初期化
  dist=[inf for i in range(points)]
  dist[start-1]=0
  
  #辺の緩和
  for i in range(points):
    for edge in edges:
      if dist[edge[0]-1]!=inf and  dist[edge[1]-1] > dist[edge[0]-1] + edge[2]:
        dist[edge[1]-1] = dist[edge[0]-1] + edge[2]
    dist1 = dist[N-1]
  for i in range(points):
    for edge in edges:
      if dist[edge[0]-1]!=inf and  dist[edge[1]-1] > dist[edge[0]-1] + edge[2]:
        dist[edge[1]-1] = dist[edge[0]-1] + edge[2]
    dist2 = dist[N-1]
  if dist1 != dist2:return "Loop"
  return (dist)

N,M,P = [int(i) for i in input().split()]
Edges = []
for i in range(M):
    a,b,c = [int(i) for i in input().split()]
    Edges.append((a,b,P-c))
dist = BellmanFord(Edges,N,1)
if dist =="Loop":
    print(-1)
else:
    print(max(-dist[N-1],0))