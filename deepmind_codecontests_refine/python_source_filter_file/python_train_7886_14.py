import sys
from collections import deque


N, M = map(int, input().split())
edge = [[] for _ in range(N)]
for s in sys.stdin.readlines():
    a, b = map(lambda x: int(x) - 1, s.split())
    edge[a].append(b)
    edge[b].append(a)

path = [-1] * N
cnt = 0
for i in range(N):
    if path[i] < 0:
        cnt += 1
        q = deque()
        path[i] = i
        q.append(i)
        while q:
            p = q.popleft()
            for np in edge[p]:
                if path[np] < 0:
                    path[np] = i
                    q.append(np)

print(cnt)
