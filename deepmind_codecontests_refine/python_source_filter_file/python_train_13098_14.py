from heapq import *

INF = 10**15

def djikstra(G,s,d):
    #d = [0]*V
    que = []
    d[s] = 0
    visited = [False] * V
    heappush(que,(0,s))
    while(len(que)!=0):
        c,v = heappop(que)
        if visited[v]:
            continue
        visited[v] = True
        for i in range(len(G[v])):
            e = G[v][i]
            if visited[e[0]]:
                continue
            if d[e[0]] > d[v] + e[1]:
                d[e[0]] = d[v] + e[1]
                heappush(que,(d[e[0]],e[0]))


n,m,s,t = map(int,input().split())
V = n
Ga = [[] for i in range(n)]
Gb = [[] for i in range(n)]
for i in range(m):
    u,v,a,b = map(int,input().split())
    Ga[u-1].append((v-1,a))
    Ga[v-1].append((u-1,a))
    Gb[u-1].append((v-1,b))
    Gb[v-1].append((u-1,b))

S = [INF]*V
T = [INF]*V
djikstra(Ga,s-1,S)
djikstra(Gb,t-1,T)
M = [0]*n
for i in range(n):
M[i] = INF-S[i]-T[i]
ans = [0]*n
ans[n-1] = M[n-1]
for i in range(n-2,-1,-1):
    ans[i] = max(ans[i+1],M[i])

for i in range(n):
    print(ans[i])
