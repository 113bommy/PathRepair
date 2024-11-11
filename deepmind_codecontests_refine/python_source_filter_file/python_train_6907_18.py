import os
import sys
if os.path.exists(r'C:\Users\User\codeforces'):
    f = iter(open('A.txt').readlines())
    def input():
        return next(f).strip()
    # input = lambda: sys.stdin.readline().strip()  
else:
    input = lambda: sys.stdin.readline().strip()
 
fprint = lambda *args: print(*args, flush=True)
 

import heapq

n, m = map(int, input().split())

g = {i : [] for i in range(n+1)}
for i in range(m):
    a, b, w = map(int, input().split())
    g[a].append( (b, w) )
    g[b].append( (a, w) )
t = {i : [] for i in range(n+1)}

M = 10**18
color = [0]*(n+1)
weight = [M]*(n+1)
weight[1] = 0
stack = [(0, 1)]
while stack:
    _, cur = heapq.heappop(stack)
    if color[cur] != 0:
        continue

    w_cur = weight[cur]
    for to, w_to in g[cur]:
        weight[to] = min(weight[to], w_cur + w_to)
        heapq.heappush(stack, (weight[to], to))
    color[cur] = 1

for cur in g:
    for to, w_to in g[cur]:
        if weight[to] == weight[cur] + w_to:
            t[cur].append(to)
            t[to].append(cur)
print(weight)
# print(t)
if weight[n] == M:
    print(-1)
else:
    dist = [M] * (n+1)
    dist[1] = 0
    stack = [1]
    color = [0]*(n+1)
    while stack:
        cur = stack[0]
        stack = stack[1:]
        if color[cur] != 0:
            continue
        d_cur = dist[cur]
        for to in t[cur]:
            dist[to] = min(dist[to], d_cur + 1)
            stack.append(to)
        color[cur] = 1
    cur = n
    path = [cur]
    while cur != 1:
        for to in t[cur]:
            # print(cur, to, dist[cur], dist[to])
            if dist[cur] == dist[to] + 1:
                cur = to
                path.append(to)
                break
    print(' '.join(map(str, reversed(path))))
