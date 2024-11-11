import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from collections import deque

N,M = map(int,readline().split())
if M == 0:
    print(-1)
    exit()
m = map(int,read().split())
P,Q,C = zip(*zip(m,m,m))

V = []
V += [p<<32 for p in range(1,N+1)]
V += [(p<<32)+c for p,c in zip(P,C)]
V += [(q<<32)+c for q,c in zip(Q,C)]
V = set(V)
label = {x:i for i,x in enumerate(V)}
start = label[1<<32]
goal = label[N<<32]

N = len(V)
graph = [[] for _ in range(N)]
for p,q,c in zip(P,Q,C):
    v0 = label[p<<32]; v1 = label[(p<<32)+c]
    w0 = label[q<<32]; w1 = label[(q<<32)+c]
    graph[v0].append((v1,1))
    graph[w0].append((w1,1))
    graph[v1].append((v0,0))
    graph[w1].append((w0,0))
    graph[v1].append((w1,0))
    graph[w1].append((v1,0))

INF = 10 ** 10
dist = [INF] * N
dist[start] = 0
q = deque([(0,start)])
while q:
    dv,v = q.popleft()
    for w,cost in graph[v]:
        dw = dv + cost
        if dw >= dist[w]:
            continue
        dist[w] = dw
        if not cost:
            q.appendleft((dw,w))
        else:
            q.append((dw,w))

answer = dist[goal]
if answer == INF:
    answer = -1
print(answer)