xs, ys, xt, yt = map(int, input().split())
n = int(input())
X = [[0, 0, 0] for _ in range(n+2)]
X[0] = [xs, ys, 0]
X[n+1] = [xt, yt, 0]
R = [0]*n
for i in range(n):
    x, y, r = map(int, input().split())
    X[i+1] = [x, y, r]

import math
edge = [[] for _ in range(n+2)]
for i in range(n+1):
    x1, y1, r1 = X[i]
    for j in range(i+1, n+2):
        x2, y2, r2 = X[j]
        l = math.sqrt((x1-x2)**2+(y1-y2)**2)
        edge[i].append((max(l-r1-r2, 0), j))
        edge[j].append((max(l-r1-r2, 0), i))

import heapq
def dijkstra_heap(s):
    d = [float("inf")] * (n+2)
    used = [True] * (n+2) #True: not used
    d[s] = 0
    used[s] = False
    edgelist = []
    for e in edge[s]:
        heapq.heappush(edgelist,e)
    while len(edgelist):
        minedge = heapq.heappop(edgelist)
        if not used[minedge[1]]:
            continue
        v = minedge[1]
        d[v] = minedge[0]
        used[v] = False
        for e in edge[v]:
            if used[e[1]]:
                heapq.heappush(edgelist,(e[0]+d[v],e[1]))
    return d

d = dijkstra_heap(0)
print(d[-1])