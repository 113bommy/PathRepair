N = int(input())
src = [int(input()) for i in range(N)]
idx = {a:i for i,a in enumerate(src)}

size = [1] * N
ss = list(sorted(src))

es = []
gr = [[] for i in range(N)]
while len(ss) > 1:
    a = ss.pop()
    k = size[idx[a]]
    b = a + 2*k - N
    if b == a or b not in idx:
        print(-1)
        exit()
    size[idx[b]] += k
    ai,bi = idx[a],idx[b]
    es.append((ai,bi))
    gr[a].append(b)
    gr[b].append(a)

from collections import deque
dist = [N] * N
dist[idx[ss[0]]] = 0
q = deque([idx[ss[0]]])
while q:
    v = q.popleft()
    for to in gr[v]:
        if dist[to] < N: continue
        q.append(to)
        dist[to] = dist[v] + 1

if all(d<N for d in dist) and sum(dist) == ss[0]:
    for a,b in es:
        print(a+1, b+1)
else:
    print(-1)