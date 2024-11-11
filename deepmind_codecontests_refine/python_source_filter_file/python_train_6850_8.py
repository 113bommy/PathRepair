N,M = map(int,input().split())
import time
start_t = time.time()
path = [[] for _ in range(N+3)]
for _ in range(M):
    u,v = map(int,input().split())
    path[u].append(v)

S,T = map(int,input().split())
import collections

q = collections.deque()
vis = [[-1 for _ in range(3)] for _ in range(N+3)]
vis[S][0] = 1
q.append([S,0])
while len(q):
    now,cnt = q.popleft()
    step = cnt % 3
    for x in path[now]:
        if vis[x][(step+1)%3] < 0:
            vis[now][(step+1)%3] = cnt
            q.append((x,cnt+1))

if vis[T][0] == -1:
    print(-1)
else:
    print(vis[T][0]//3)

