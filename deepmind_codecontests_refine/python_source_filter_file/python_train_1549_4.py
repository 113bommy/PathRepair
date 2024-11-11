from collections import deque

N, K = map(int, input().split())
T = [[] for i in range(N)]
E = []
for i in range(N-1):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    T[a].append(b)
    T[b].append(a)
    E.append((a, b))


def dfs(n):
    visited = [False] * N
    stack = [[n, 0]]
    longest = [-1, -1]

    while stack:
        node, weight = stack.pop()
        if visited[node]:
            continue
        visited[node] = True
        if longest[1] < weight:
            longest = [node, weight]

        for n in T[node]:
            if not visited[n]:
                stack.append([n, weight + 1])

    return longest


def bfs(n):
    visited = [False] * N
    dist = [0] * N
    queue = deque([n])
    while queue:
        node = queue.pop()
        if visited[node]:
            continue
        visited[node] = True
        for n in T[node]:
            if not visited[n]:
                dist[n] = dist[node] + 1
                queue.appendleft(n)
    return dist


xn, xw = dfs(0)
yn, yw = dfs(xn)
diameter = yw

d = bfs(0)
ans = float('inf')
if diameter % 2 == 0:
    # 全ての頂点について全探索
    for i in range(N):
        dist = bfs(i)
        ans = min(ans, len(list(filter(lambda x: K / 2 < x, dist))))
else:
    # 全ての辺について全探索
    for a, b in E:
        dist1 = bfs(a)
        dist2 = bfs(b)
        dist = [min(d1, d2) for d1, d2 in zip(dist1, dist2)]
        ans = min(ans, len(list(filter(lambda x: (K-1) / 2 < x, dist))))

print(ans)
