from itertools import count
N,M = map(int,input().split())

adj = [list() for _ in range(N)]


for _ in range(M):
    u,v = map(int,input().split())
    adj[u-1].append(v-1)

S,T = map(int,input().split())
S,T = S-1,T-1

visited = [False]*(N*3)
visited[S] = True
q = [S]

for step in count():
    offset = N*(step % 3)
    nq = []
    for u in q:
        for v in adj[u]:
            if not visited[v+offset]:
                nq.append(v)
                visited[v+offset] = True
    q = nq

    if visited[T] or not q:
        break
if visited[T]:
    print(step//3)
else:
    print(-1)