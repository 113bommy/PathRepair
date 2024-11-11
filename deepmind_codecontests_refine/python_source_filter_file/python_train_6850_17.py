from collections import deque

N, M = map(int, input().split())
E = {u: set() for u in range(1, N+1)}
for i in range(M):
    u, v = map(int, input().split())
    E[u].add(v)
S, T = map(int, input().split())

X = {}
for u in E:
    for i in range(3):
        X[(u, i)] = set([(v, (i + 1) % 3) for v in E[u]])

# bfs
queue = deque(maxlen=N)
queue.append(((S, 0), 0))
visited = set()

while len(queue) > 0:
    u, n = queue.popleft()
    if u in visited:
        continue
    visited.add(u)
    if u == (T, 0):
        print(n // 3)
        exit()
    for v in X[u]:
        queue.append((v, n + 1))

print(-1)
