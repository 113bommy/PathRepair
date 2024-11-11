from sys import stdin
from collections import deque
n = int(stdin.readline())
M = [[0] * (n + 1) for _ in range(n + 1)]
d = [200] * (n + 1)
def bfs():
    d[1] = 0
    dq = deque()
    dq.append(1)
    while len(dq) > 0:
        u = dq.pop()
        for v in range(1, n + 1):
            if M[u][v] == 0 or d[v] != 200: continue
            d[v] = d[u] + 1
            dq.append(v)
    for i in range(1, n + 1):
        print(i, (-1 if d[i] == 200 else d[i]))
for u in range(1, n + 1):
    U = [int(j) for j in stdin.readline().split()]
    for v in U[2:]:
        M[u][v] = 1
bfs()