ai = lambda: list(map(int, input().split()))

n, m = ai()

from collections import defaultdict as dd

edge = dd(list)
for _ in range(m):
    a, b, c = ai()
    edge[a - 1].append([b - 1, -c])

dist = [float('inf')] * n
dist[0] = 0
vs = {0}
i = 0
while vs:
    cur_v = vs.pop()
    for v, c in edge[cur_v]:
        if dist[v] > dist[cur_v] + c:
            dist[v] = dist[cur_v] + c
            vs.add(v)
            if i == n and v == n-1:
                print('inf')
                exit()
    i += 1
    if i > n:
        break
print(-dist[-1])