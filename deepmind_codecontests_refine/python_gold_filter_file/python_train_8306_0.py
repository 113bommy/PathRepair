n = int(input())
link = [[] for _ in range(n)]
for i in range(n-1):
    a,b = list(map(int,input().split()))
    link[a-1].append(b-1)
    link[b-1].append(a-1)

from collections import deque
def bfs(s):
    dist = [None]*n
    que = deque([s])
    dist[s] = 0
    while que:
        v = que.popleft()
        d = dist[v]
        for w in link[v]:
            if dist[w] is not None:
                continue
            dist[w] = d + 1
            que.append(w)
    d = max(dist)
    return dist.index(d), d
u, _ = bfs(0)
v, d = bfs(u)

if (d-1)%3==0:
    print("Second")
else:
    print("First")