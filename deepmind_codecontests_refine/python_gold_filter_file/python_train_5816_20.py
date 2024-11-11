from heapq import*

def Dijkstra(G: list, source=0):
	INF = float("inf")
	V = len(G)
	D = [INF] * V
	D[source] = 0
	vis = [False] * V
	H = [(0, source)]
	while H:
		dist, cur = heappop(H)
		if vis[cur]:
			continue
		vis[cur] = True
		for nxt, cost in G[cur]:
			t = dist + cost
			if D[nxt] > t:
				D[nxt] = t
				heappush(H, (t, nxt))
	return D

import sys
input = sys.stdin.buffer.readline
from math import hypot
sx,sy,gx,gy=map(int,input().split())
n=int(input())
v=[(sx,sy,0),(gx,gy,0)]
for _ in range(n):
	v.append(tuple(map(int,input().split())))
con=[[] for _ in range(n+2)]
for i,p1 in enumerate(v):
	for j,p2 in enumerate(v[i+1:]):
		t=max(0,hypot(p1[0]-p2[0],p1[1]-p2[1])-p1[2]-p2[2])
		con[i].append((i+j+1,t))
		con[i+j+1].append((i,t))
print(Dijkstra(con)[1])
