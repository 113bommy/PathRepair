from collections import deque

N, M = map(int, input().split())

dp = [0] * N
E = [[] for _ in range(N)]
deg = [0] * N
for _ in range(M):
    x, y = map(int, input().split())
    E[x-1].append(y-1)
    deg[y-1] += 1

que = deque(i for i in range(N) if deg[i] == 0)
while que:
    v = que.pop()
    for u in E[v]:
        deg[u] -= 1
        if deg[u] == 0:
            que.append(u)
            dp[u] = max(dp[u], dp[v] + 1)

print(max(dp))
