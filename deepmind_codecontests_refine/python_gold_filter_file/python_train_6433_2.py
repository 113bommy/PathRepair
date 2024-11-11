n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]
indeg = [0] * (n+1)
outdeg = [0] * (n+1)
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indeg[b] += 1
    outdeg[a] += 1

is_valid = [indeg[i] * outdeg[i] for i in range(n+1)]
u = n+10
ans = []
from collections import deque
for start in range(1, n+1):
    if not is_valid[start]:
        continue

    # print("start: ", start, "---------")
    q = deque([start])
    visited = [False] * (n+1)
    prev = [-1] * (n+1)
    visited[start] = True

    has_ans = False
    while q:
        now = q.popleft()
        # print("now", now)
        for node in graph[now]:
            if node == start:
                # print("roop")
                prev[node] = now
                has_ans = True
                break
            if visited[node] or not is_valid[node]:
                continue
            # print("  to: ", node)
            prev[node] = now
            visited[node] = True
            q.append(node)
        if has_ans:
            break

    if not has_ans:
        continue
    cnt = 0
    tmp = []
    now = start
    for _ in range(n):
        tmp.append(now)
        cnt += 1
        now = prev[now]
        if now == start or now == -1:
            break
    if cnt < u:
        u = cnt
        ans = tmp

if ans:
    print(u)
    for t in ans:
        print(t)
else:
    print(-1)