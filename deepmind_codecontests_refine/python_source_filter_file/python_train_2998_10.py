import sys
from collections import deque
inputs = sys.stdin.readlines()

n = int(inputs[0])
edges = [tuple(map(int, x.split())) for x in inputs[1:]]
B = [e[1] for e in edges] 

E = [[] for _ in range(N + 1)]
for a, b in edges:
    E[a].append(b)

Q = deque([1])
C = [0] * (N + 1)
while Q:
    v = Q.popleft()
    c = 0
    for u in E[v]:
        c += 1 + (c + 1 == C[v])
        C[u] = c
        Q.append(u)

print(max(C))
for b in B:
    print(C[b])