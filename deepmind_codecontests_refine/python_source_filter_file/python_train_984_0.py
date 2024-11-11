def dfs_paths(graph, start, goal, path=list()):
    if not path:
        path.append(start)
    if start == goal:
        yield path
    for vertex in graph[start] - set(path):
        yield from dfs_paths(graph, vertex, goal, path=path + [vertex])

n, m = map(int, input().split())
graph = {}

for _ in range(m):
    a, b, c = map(int, input().split())

    if c not in graph:
        graph[c] = {}

    if a not in graph[c]:
        graph[c][a] = set()

    if b not in graph[c]:
        graph[c][b] = set()

    graph[c][a].add(b)
    graph[c][b].add(a)

q = int(input())

for _ in range(q):
    u, v = map(int, input().split())
    count = 0

    for k in graph:
        if u not in graph[k] or v not in graph[k]:
            continue
        if len(list(dfs_paths(graph[k], u, v))) > 0:
            count += 1

    print(count)
