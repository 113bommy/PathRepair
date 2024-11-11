import sys
sys.setrecursionlimit(10**9)

N,M,P = map(int,input().split())
edges = []
to = [[] for i in range(N)]
rto = [[] for i in range(N)]
for i in range(M) :
    u,v,cost = map(int,input().split())
    u -= 1
    v -= 1
    cost -= P
    cost *= -1
    edges.append([u,v,cost])
    to[u].append(v)
    rto[v].append(u)

canVisitFromS = [False]*N
canVisitFromG = [False]*N

def dfs(u) :
    if canVisitFromS[u] : return
    canVisitFromS[u] = True
    for v in to[u] :
        dfs(v)

def rdfs(v) :
    if canVisitFromG[v] : return
    canVisitFromG[v] = True
    for u in rto[v] :
        rdfs(u)

dfs(0)
rdfs(N-1)

OK = [canVisitFromS[i]*canVisitFromG[i] for i in range(N)]

dist = [float("inf")]*N
dist[0] = 0

ans = 0
step = 0
update = True
while update :
    update = False
    for i in range(M) :
        u,v,cost = edges[i]
        if OK[u]*OK[v] == 0 : continue
        if dist[v] > dist[u] + cost :
            dist[v] = dist[u] + cost
            update = True
    step += 1
    if step > N :
        ans = -1
        break

if ans != -1 :
    ans = max(0, dist[N-1]*(-1))

print(ans)