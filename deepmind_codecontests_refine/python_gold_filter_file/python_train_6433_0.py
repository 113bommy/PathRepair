import sys
from collections import deque
N, M = map(int, input().split())
edges = [[] for i in range(N)]
AB = []
for _ in range(M):
    a, b = map(int, input().split())
    edges[a-1].append(b-1)
    AB.append((a-1, b-1))
def BFS(s):
    prev = [-1]*N
    que = deque([s])
    while que:
        v = que.pop()
        for nv in edges[v]:
            if nv == s:
                prev[nv] = v
                return (s, prev)
            if prev[nv]<0:
                que.append(nv)
                prev[nv] = v
    return (-1, prev)
for v in range(N):
    v0, prev = BFS(v)
    if v0>=0:
        break
if v0<0:
    print(-1)
    sys.exit()
circle = set()
circle.add(v0)
pv = prev[v0]
while pv != v0:
    circle.add(pv)
    pv = prev[pv]
for a, b in AB:
    if a in circle and b in circle and prev[b] != a:
        pv = prev[b]
        while pv != a:
            circle.remove(pv)
            pv = prev[pv]
        prev[b] = a
print(len(circle))
for i in circle:
    print(i+1)