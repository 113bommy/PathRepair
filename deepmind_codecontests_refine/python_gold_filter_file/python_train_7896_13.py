from collections import defaultdict
from collections import deque

N, M = map(int, input().split())

chg = 10**6
G = defaultdict(set)
for _ in range(M):
    p, q, c = map(int, input().split())
    # 無向グラフ
    G[p].add(p+chg*c)
    G[p+chg*c].add(p)
    G[q].add(q+chg*c)
    G[q+chg*c].add(q)
    G[p+chg*c].add(q+chg*c)
    G[q+chg*c].add(p+chg*c)


dist = defaultdict(lambda: 10**11)
dist[1] = 0

que = deque([1])

while que:
    ci = que.popleft()

    for ni in G[ci]:
        if dist[ni] == 10**11:
            if ci >= chg and ni >= chg:
                dist[ni] = dist[ci]
                que.appendleft(ni)
            else:
                dist[ni] = dist[ci]+1
                que.append(ni)


if dist[N] < 10**11:
    print(dist[N]//2)
else:
    print(-1)
