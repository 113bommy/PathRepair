from sys import stdin
from collections import deque
n = int(input())
d = [-1] * (n + 1)
def bfs():
    d[1] = 0
    dq = deque([1])
    while len(dq) != 0:
        v = dq.popleft()
        for c in G[v]:
            if d[c] != -1 : continue
            d[c] = d[v] + 1
            dq.append(c)
    for i, x in enumerate(d[1:], start=1):
        print(i, x)
G = [0] + [list(map(int, input().split()[2:])) for _ in range(n)]
bfs()