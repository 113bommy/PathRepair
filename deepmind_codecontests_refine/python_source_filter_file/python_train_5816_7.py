import sys
input = sys.stdin.readline
 
from heapq import heappop,heappush
import math
 
xs,ys,xt,yt = map(int,input().split())
n = int(input())
 
v = [[xs,ys,0]]
for _ in range(n):
    x,y,r = map(int,input().split())
    v.append([x,y,r])
v.append([xt,yt,0])
 
def dd(a,b):
    return max(0,math.sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2) - a[2] - b[2])

edges=[[0]*(n+2) for _ in range(n+2)]
for i in range(n+2):
    for j in range(i+1,n+2):
        edges[i][j] = dd(v[i],v[j])
        edges[j][i] = dd(v[i],v[j])

def dijkstra(s,n,edges):
    #edges[i][j] : the cost of i→j
    #import 'heap'
    d = [float('inf') for _ in range(n)]
    d[s] = 0
    q = [[0, s]]
    while q:
        dist_u, u = heappop(q)
        if d[u] < dist_u:
            continue
        for v, c in enumerate(edges[u]):
            if d[v] > dist_u + c:
                d[v] = dist_u + c
                heappush(q, [d[v], v])
    return d

ans = dijkstra(0,n+2,edges)
print(ans[n+1])