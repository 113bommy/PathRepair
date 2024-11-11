import math
import sys
sys.setrecursionlimit(20000)
N=int(input())
edges=[[] for i in range(N+1)]
d=[-1 for i in range(N+1)]
for i in range(1,N):
	u,v,w=[int(i) for i in input().split()]
	edges[u].append([v,w])
	edges[v].append([u,w])
def kyori(u):
	for v,w in edges[u]:
		if d[v]==-1:
			d[v]=d[u]+w
			kyori(v)
d[1]=0
kyori(1)
for i in d[1:]:
	if i%2==0:
		print(1)
	else:
		print(0)