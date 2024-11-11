N = int(input())
from collections import defaultdict
flag = [0 for i in range(N)]
G = defaultdict(list)
for _ in range(N-1):
    a,b = map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)

# G[v]: 頂点vに隣接する頂点list
# N: 頂点数

from collections import deque
dist = [-1]*N
que = deque([0])
dist[0] = 0
while que:
    v = que.popleft()
    d = dist[v]
    for w in G[v]:
        if dist[w] > -1:
            continue
        dist[w] = d + 1
        que.append(w)


al = [0, 0]
for d in dist:
    al[d%2] += 1
if sum(al) // al[0] > 3:
    numbers1 = [i for i in range(1, N + 1) if i % 3 == 1]
    numbers2 = [i for i in range(1, N + 1) if i % 3 == 2]
    numbers3 = [i for i in range(1, N + 1) if i % 3 == 0]
    ansl = []
    for d in dist:
        if d % 2 == 0:
            ansl.append(numbers3.pop())
        else:
            if numbers1:
                ansl.append(numbers1.pop())
            elif numbers2:
                ansl.append(numbers2.pop())
            else:
                ansl.append(numbers3.pop())
    for a in ansl:
        print(a)
elif sum(al) // al[1] > 3:
    numbers1 = [i for i in range(1, N + 1) if i % 3 == 1]
    numbers2 = [i for i in range(1, N + 1) if i % 3 == 2]
    numbers3 = [i for i in range(1, N + 1) if i % 3 == 0]
    ansl = []
    for d in dist:
        if d % 2 == 0:
            if numbers1:
                ansl.append(numbers1.pop())
            elif numbers2:
                ansl.append(numbers2.pop())
            else:
                ansl.append(numbers3.pop())
        else:
            ansl.append(numbers3.pop())
    for a in ansl:
        print(a)
else:
    numbers1 = [i for i in range(1, N + 1) if i % 3 == 1]
    numbers2 = [i for i in range(1, N + 1) if i % 3 == 2]
    numbers3 = [i for i in range(1, N + 1) if i % 3 == 0]
    ansl = []
    for d in dist:
        if d % 2 == 0:
            if numbers1:
                ansl.append(numbers1.pop())
            else:
                ansl.append(numbers3.pop())
        else:
            if numbers2:
                ansl.append(numbers2.pop())
            else:
                ansl.append(numbers3.pop())
    for a in ansl:
        print(a)
