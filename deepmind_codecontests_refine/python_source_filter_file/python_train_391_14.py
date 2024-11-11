from collections import deque

def bfs(s):
    que = deque([(s, 0)])
    dist = [None]*n
    while que:
        cur, cst = que.popleft()
        if dist[cur] != None:
            continue
        dist[cur] = cst
        for nxt in es[cur]:
            que.append((nxt, cst+1))
    return dist

n,u,v = map(int,input().split())
es = [[] for _ in range(n)]
for _ in range(n-1):
    a,b = map(int,input().split())
    es[a-1].append(b-1)
    es[b-1].append(a-1)
dist_u = bfs(u-1)
dist_v = bfs(v-1)

ans = 0
for i in range(n):
    if dist_u[i] -dist_v[i] > 1:
        ans = max(ans, dist_u[i])
print(max(0, ans-1))
