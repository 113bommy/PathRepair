import sys;input=sys.stdin.readline
from collections import defaultdict, deque
T, = map(int, input().split())
for _ in range(T):
    N, M = map(int, input().split())
    G = [set() for _ in range(N+1)]
    es = []
    ees = []
    D = defaultdict(int)
    in_cnt = defaultdict(int)
    outs = defaultdict(int)
    for _ in range(M):
        t, x, y = map(int, input().split())
        if t:
            G[x].add(y)
            in_cnt[y] += 1
            ees.append((x, y))
        else:
            es.append((x, y))

    res = []
    queue = deque([i for i in range(1, N+1) if in_cnt[i] == 0])
    v2i = dict()
#    print(queue, N)
    while len(queue) != 0:
        v = queue.popleft()
        res.append(v)
        for v2 in G[v]:
            in_cnt[v2] -= 1
            if in_cnt[v2] == 0:
                queue.append(v2)
    if len(res) != N:
        print("NO")
        continue
    print("YES")
    for i in range(N):
        v2i[res[i]] = i
    for x, y in es:
        if v2i[x] < v2i[y]:
            print(x, y)
        else:
            print(y, x)
    for x, y in ees:
        print(x, y)

