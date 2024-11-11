N, M = map(int, input().split())
from collections import defaultdict, deque

graph = defaultdict(list)
for i in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    graph[u].append(v + N)
    graph[u + N].append(v + 2 * N)
    graph[u + 2 * N].append(v)
S, T = map(int, input().split())
S -= 1
T -= 1

dist = [-1] * (3*N)
dist[S] = 0
que = deque([S])
while len(que) != 0:
    q = que.popleft()
    cost = dist[q]
    for v in graph[q]:
        if dist[v] == -1:
            dist[v] = cost + 1
            que.append(v)
if dist[T] % 3 == 0:
    print(dist[T] // 3)
else:
    print(-1)
