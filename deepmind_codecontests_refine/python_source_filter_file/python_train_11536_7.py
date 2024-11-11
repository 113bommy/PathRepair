N, M = map(int, input().split())

if M % 2 != 0:
    print(-1)
    exit()

graph = [[] for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)

ans = []
parent = [-1] * N
visited = [False] * N
ctr = [0] * N
record = []
que = [(-1, 0)]

while que:
    pre, u = que.pop()
    if visited[u]:
        ctr[u] += 1
        if pre >= 0:
            ans.append((u, pre))
        continue
        
    visited[u] = True
    record.append(u)
    for v in graph[u]:
        if v != parent[u]:
            parent[v] = u
            graph[u].remove(v)
            que.append((u, v))
            
for u in record[1:][::-1]:
    if ctr[u] % 2 == 1:
        ans.append((u, parent[u]))
    else:
        ans.append((parent[u], u))
        ctr[parent[u]] += 1
        
for x, y in ans:
    print(x + 1, y + 1)


