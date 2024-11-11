import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)
from collections import deque, defaultdict
N, M = map(int, input().split())
G = defaultdict(list)
for _ in range(M):
    p, q, c = map(int, input().split())
    G[(p-1, c-1)].append((p-1, -1))
    G[(q-1, c-1)].append((q-1, -1))
    G[(p-1, -1)].append((p-1, c-1))
    G[(q-1, -1)].append((q-1, c-1))
    G[(p-1, c-1)].append((q-1, c-1))
    G[(q-1, c-1)].append((p-1, c-1))


dist = defaultdict(lambda :-1)
que = deque([(0, -1)])
dist[(0, -1)] = 0
while que:
    v = que.pop()
    d = dist[v]
    for nv in G[v]:
        if dist[nv]<0:
            if nv[1] == -1:
                dist[nv] = d+1
                que.appendleft(nv)
            else:
                dist[nv] = d
                que.append(nv)
print(dist[(N-1, -1)])



