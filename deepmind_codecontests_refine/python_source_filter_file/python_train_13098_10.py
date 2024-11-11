import sys
input=sys.stdin.readline

import heapq

def dijkstra(s,edge):
    #始点sから各頂点への最短距離
    d = [float("inf")] * n
    used = [True] * n #True:未確定
    d[s] = 0
    used[s] = False
    edgelist = []
    for e in edge[s]:
        heapq.heappush(edgelist,e)
    while len(edgelist):
        minedge = heapq.heappop(edgelist)
        #まだ使われてない頂点の中から最小の距離のものを探す
        if not used[minedge[1]]:
            continue
        v = minedge[1]
        d[v] = minedge[0]
        used[v] = False
        for e in edge[v]:
            if used[e[1]]:
                heapq.heappush(edgelist,[e[0]+d[v],e[1]])
    return d

n,m,s,t=map(int,input().split())
s,t=s-1,t-1
edge1=[[] for _ in range(n)]
edge2=[[] for _ in range(n)]
for _ in range(m):
  u,v,a,b=map(int,input().split())
  edge1[u-1].append([a,v-1])
  edge1[v-1].append([a,u-1])
  edge2[u-1].append([b,v-1])
  edge2[v-1].append([b,u-1])
d1=dijkstra(s,edge1)
d2=dijkstra(t,edge1)
INF=10**15
ans=[INF]*n
ans[n-1]=int(d1[n-1]+d2[n-1])
for i in range(n-2,-1,-1):
  tmp=int(d1[i]+d2[i])
  ans[i]=min(tmp,ans[i+1])
for i in range(n):
  print(INF-ans[i])