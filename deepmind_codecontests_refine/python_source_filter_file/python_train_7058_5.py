# 解説AC
from collections import deque

N = int(input())
edge = [[] for _ in range(N)]
for _ in range(N - 1):
    a,b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
C = [int(i) for i in input().split()]

C.sort()

M = sum(C) - C[0]
d = [-1] * N

que = deque([0])
while que:
    v = que.popleft()
    d[v] = C.pop()
    for w in edge[v]:
        if d[w] < 0:
            que.append(w)

print(M)
print(*d)