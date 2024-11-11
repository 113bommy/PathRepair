import sys
from collections import deque

# 最短経路に閉路がくっついているとは限らなかった・・・

read = sys.stdin.read
N, M, *uv, S, T = map(int, read().split())

graph = [[] for _ in range(N + 1)]
for u, v in zip(*[iter(uv)] * 2):
    graph[u].append(v)

INF = 10 ** 15
# [けん,けんけん,けんけんぱ] * (N + 1)
dist = [[INF] * (N + 1) for _ in range(3)]
stack = deque([(0, S)])

while stack:
    cost, v = stack.popleft()
    if dist[cost % 3][v] != INF:
        continue

    dist[cost % 3][v] = cost
    for i in graph[v]:
        stack.append((cost + 1, i))

if dist[0][T] == INF:
    print(-1)
else:
    print(dist[0][T] // 3)
