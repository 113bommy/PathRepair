from collections import deque
N, M = map(int, input().split())
G = [set() for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a - 1].add(b - 1)
    G[b - 1].add(a - 1)
d = [0] * N
Q = deque()
for i in range(N):
    if d[i] != 0:
        continue
    Q.append(i)
    d[i] = 1
    while len(Q) > 0:
        q = Q.popleft()
        for g in G[q]:
            if d[g] != 0:
                continue
            d[q] += 1
            d[g] = -1
            Q.append(g)
print(max(d))