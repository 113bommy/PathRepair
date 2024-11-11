class Dijkstra():
  class Edge():
    # weighted directed edge
    def __init__(self,_to,_cost):
      self.to=_to
      self.cost=_cost
  def __init__(self,V):
    # 0-indexed
    self.G=[[] for i in range(V)]
    self._E=0
    self._V=V
  def E(self):
    # number of edge
    return self._E
  def V(self):
    # number of vertex
    return self._V
  def add(self, _from, _to, _cost):
    # add vertex and edge cost
    self.G[_from].append(self.Edge(_to, _cost))
    self._E+=1
  def shortest_path(self,s):
    # return the list of shortest pathes from s to each vertex
    import heapq
    que=[]
    d=[float('inf')]*self._V
    d[s]=0
    heapq.heappush(que,(0,s))
    while que:
      cost,v=heapq.heappop(que)
      if d[v]<cost:continue
      for i in range(len(self.G[v])):
        e=self.G[v][i]
        if d[e.to]>d[v]+e.cost:
          d[e.to]=d[v]+e.cost
          heapq.heappush(que,(d[e.to],e.to))
    return d

import sys
input=sys.stdin.readline
xs,ys,xt,yt=map(int,input().split())
n=int(input())
xyr=[list(map(int,input().split())) for i in range(n)]
graph=[[10**9]*(n+2) for i in range(n+2)]
graph[0][n+1]=graph[n+1][0]=((xs-xt)**2+(ys-yt)**2)**0.5
for i in range(1,n+1):
  for j in range(1,n+1):
    d=((xyr[i-1][0]-xyr[j-1][0])**2+(xyr[i-1][1]-xyr[j-1][1])**2)**0.5
    graph[i][j]=graph[j][i]=max(0,d-xyr[i-1][2]-xyr[j-1][2])
for i in range(1,n+1):
  d1=((xs-xyr[i-1][0])**2+(ys-xyr[i-1][1])**2)**0.5
  d2=((xt-xyr[i-1][0])**2+(yt-xyr[i-1][1])**2)**0.5
  graph[0][i]=graph[i][0]=max(0,d1-xyr[i-1][2])
  graph[n+1][i]=graph[i][n+1]=max(0,d2-xyr[i-1][2])
d=Dijkstra(n+2)
for i in range(n+2):
  for j in range(n+2):
    d.add(i,j,graph[i][j])
print(d.shortest_path(0)[n+1])