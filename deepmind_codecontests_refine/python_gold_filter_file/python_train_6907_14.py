import heapq
from collections import defaultdict

def solve(n):
    distances = [10**18 for i in range(n + 5)]
    Q = list()
    heapq.heappush(Q, (0, 1))
    paths[1] = 1
    distances[1] = 0
    while Q:
        c, u = heapq.heappop(Q)
        if u == n:
            return c
        if distances[u] < c:
            continue
        for w, v in Graph[u]:
            if distances[v] > c + w:
                distances[v] = c + w
                heapq.heappush(Q, (distances[v], v))
                paths[v] = u
    return -1

Graph = defaultdict(list)
paths = defaultdict(int)
arr = list()

n, m = map(int, input().split())

for i in range(m):
    x, y, c = map(int, input().split())
    Graph[x].append((c, y))
    Graph[y].append((c, x))

if solve(n) != -1:
    while(paths[n] != n):
        arr.append(n)
        n = paths[n]
else:
    print(-1)
    exit()

arr.append(1)

print(' '.join(map(str, arr[::-1])))
