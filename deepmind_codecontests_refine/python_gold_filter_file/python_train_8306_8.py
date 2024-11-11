from collections import deque
N = int(input())
edges = [[] for _ in range(N)]
for _ in range(N-1):
    a, b = map(int, input().split())
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)

def bfs(v0):
    dist = [-1]*N
    que = deque([v0])
    dist[v0] = 0
    while que:
        v = que.pop()
        d = dist[v]
        for nv in edges[v]:
            if dist[nv] < 0:
                que.append(nv)
                dist[nv] = d+1
    m = max(dist)
    v = dist.index(m)
    return v, m
u, _ = bfs(0)
_, dia = bfs(u)
if N == 1:
    print('First')
elif (dia+1-2)%3 == 0:
    print('Second')
else:
    print('First')
