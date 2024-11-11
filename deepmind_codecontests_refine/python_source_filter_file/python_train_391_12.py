from collections import deque
n, u, v = map(int, input().split())
u-=1; v-=1;
a = []; b = [];
dist = [[] for i in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1; b -= 1
    dist[a].append(b)
    dist[b].append(a)

def bfs(u):
    d = [-1]*n
    stack = deque([u])
    d[u] = 0
    while len(stack)!=0:
        s = stack.popleft()
        for t in dist[s]:
            if d[t]==-1:
                d[t] = d[s]+1
                stack.append(t)
    return d

A = bfs(v)
T = bfs(u)
ans=0
for i in range(n):
    if A[i]>d[i]:
        ans = max(A[i]-1, ans)
print(ans)