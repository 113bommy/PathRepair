# coding: utf-8
# Your code here!

def Bellman_Ford(g,start):
    n = len(g)    
    dist = [float("inf")]*n
    dist[start] = 0
    a0 = float("inf")
    negative = [False]*n
    for i in range((2*n)):
        updated = False
        for v in range(n):
            for to, cost in g[v]:
                if negative[v]: negative[to] = True
                if dist[to] <= dist[v] + cost: continue
                dist[to] = dist[v] + cost
                updated = True
                if i >= n:
                    negative[to] = True
        if not updated: break
    if negative[-1]: return None, False
    return dist, True
 

import sys
sys.setrecursionlimit(10**6)
readline = sys.stdin.readline #文字列入力のときは注意

n,m,p = [int(i) for i in readline().split()]
g = [[] for _ in range(n)]
for i in range(m):
    a,b,c = [int(i) for i in readline().split()]
    g[a-1].append((b-1,-c+p))
#    g[b-1].append((a-1,c))

dist, TF = Bellman_Ford(g, 0)

if TF: print(max(-dist[-1],0))
else: print(-1)


