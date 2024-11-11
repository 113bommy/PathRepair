from collections import defaultdict, deque
N, M = map(int, input().split())
G = defaultdict(list)
for _ in range(M):
    u, v = map(int, input().split())
    G[(u-1, 0)].append((v-1, 1))
    G[(u-1, 1)].append((v-1, 2))
    G[(u-1, 2)].append((v-1, 0))
S, T = map(int, input().split())
dist = defaultdict(lambda : -1)
que = deque([(S-1, 0)])
dist[(S-1, 0)] = 0
while que:
    v = que.popleft()
    d = dist[v]
    for nv in G[v]:
        if dist[nv]>=0:
            continue
        dist[nv] = d+1
        que.append(nv)
print(dist[(T-1, 0)]//3)
