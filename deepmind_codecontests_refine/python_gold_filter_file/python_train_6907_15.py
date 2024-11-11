import sys, heapq

n, m = [int(x) for x in sys.stdin.readline().split()]
e = {}
for i in range(1, n+1):
    e[i] = {}

for i in range(m):
    v, u, w = [int(x) for x in sys.stdin.readline().split()]
    if not u in e[v] or e[v][u] > w: e[v][u] = w
    if not v in e[u] or e[u][v] > w: e[u][v] = w

INF = 1000000000000

pq = []
heapq.heappush(pq, (0, n))
prev = [-1]*(n+1)
dist = [INF]*(n+1)
vis = [False]*(n+1)
dist[n] = 0


while len(pq) > 0:
    d, v = heapq.heappop(pq)
    if vis[v]: continue
    vis[v] = True
    
    if v == 1: break
    
    for u in e[v]:
        alt = dist[v] + e[v][u]
        if alt < dist[u]:
            dist[u] = alt
            prev[u] = v
            heapq.heappush(pq, (alt, u))

p = 1
patth = []
while p != -1:
    patth.append(str(p))
    p = prev[p]
if patth[-1] != str(n): print(-1)
else: print(" ".join(patth))