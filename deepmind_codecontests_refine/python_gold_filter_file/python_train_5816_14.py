xs,ys,xt,yt = map(int, input().split())
n = int(input())
c = [(xs,ys, 0),(xt,yt,0)]
for i in range(n):
    x,y,r = map(int, input().split())
    c.append((x,y,r))

def circle_circle(ax,ay,ar,bx,by,br):
    d =((ax-bx)**2 + (ay-by)**2)**0.5
    return max(0, d-(ar+br))

def dijkstra(V, edges, root):
    import heapq

    visited = [False] * V
    nodes = [[] for i in range(V)]
    cost = [[] for i in range(V)]

    for e in edges:
        s, t, d = e
        nodes[s].append(t)
        cost[s].append(d)

    dist = [float('inf')] * V
    dist[root] = 0

    h = [(0, root)]
    while h:
        c, v = heapq.heappop(h)
        if visited[v]:
            continue
        visited[v] = True
        for i in range(n+1):
            t = nodes[v][i]
            nc = c + cost[v][i]
            if dist[t] > nc:
                dist[t] = nc
                heapq.heappush(h, (nc, t))
    return dist
edges = []
for i in range(n+1):
    for j in range(i+1, n+2):
        d = circle_circle(c[i][0],c[i][1],c[i][2],c[j][0],c[j][1],c[j][2])
        edges.append((i,j,d))
        edges.append((j,i,d))
dij = dijkstra(n+2, edges, 0)
print(dij[1])
