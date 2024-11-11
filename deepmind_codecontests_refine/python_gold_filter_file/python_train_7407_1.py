from collections import deque

def bfs(u):
    global n, al, dist, prev, used
    q = deque()
    q.append(u)
    md = 1
    used[u] = True
    while len(q) > 0:
        v = q.popleft()
        for i in al[v]:
            if not used[i]:
                used[i] = True
                dist[i] = dist[v] + 1
                if dist[i] + 1 > md:
                    md = dist[i] + 1
                q.append(i)
    return md

n = int(input())
al = [[] for i in range(n)]
dist = [0] * n
prev = [0] * n
used = [False] * n
p = [-1] * n
for i in range(n):
    x = int(input()) - 1
    if x >= 0:
        p[i] = x
        al[x].append(i)
res = 0
a = []
for i in range(n):
    if p[i] == -1:
        a.append(i)
i = 0
while i < len(a):
    if not used[a[i]]:
        res = max(res, bfs(a[i]))
    else:
        i += 1
print(res)