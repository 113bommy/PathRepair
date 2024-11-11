#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1

n,m,p=map(int,input().split())
E=[]
for i in range(m):
	a,b,c=map(int,input().split())
	a-=1; b-=1; c-=p; c*=-1
	E.append((a,b,c))

def BellmanFord(edges,n,s):
	#edgesは有向グラフの辺集合で辺は(始点,終点,コスト)
  #グラフの初期化
  dist=[inf for i in range(n)]
  dist[s]=0
  
  #辺の緩和
  for i in range(n+10000):
    update = False
    for u,v,cost in edges:
      if dist[u] != inf and dist[v] > dist[u] + cost:
        dist[v] = dist[u] + cost
        if i>=n+5000: dist[v]=inf
        update = True
  return dist
  #   if i==n-2: data=dist[n-1]
  # return -1 if dist[n-1] < data else dist

dist = BellmanFord(E,n,0)
if dist == inf:
	print(-1)
else:
	print(max(0,-dist[n-1]))

	