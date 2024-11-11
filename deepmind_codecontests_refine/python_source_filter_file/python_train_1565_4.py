from collections import defaultdict
import sys
sys.setrecursionlimit(2*sys.getrecursionlimit())
V, E = map(int, input().split())
G = defaultdict(list)
T = defaultdict(list)
for i in range(E):
    s,t = map(int, input().split())
    G[s].append(t)
    G[t].append(s)

prenum = [float('inf')] * V
lowest = [float('inf')] * V
parent = [None] * V
visited = [False] * V

def dfs(g,s,c=0,p=None):    
    visited[s] = True
    prenum[s] = c
    lowest[s] = c
    c+=1    
    for v in g[s]:
        if not visited[v]:
            parent[v] = s
            T[v].append(s)
            T[s].append(v)
            dfs(g,v,c,s)
            lowest[s] = min( lowest[s], lowest[v] )
        elif v != p:
            lowest[s] = min( lowest[s], prenum[v] )

dfs(G,0)
k = []
if len(T[0]) > 1: k.append(0)
for u in range(V):
    p = parent[u]
    if p is None or p == 0: continue
    if prenum[p] <= lowest[u]: k.append(p)
for i in sorted(set(k)):
    print(i)