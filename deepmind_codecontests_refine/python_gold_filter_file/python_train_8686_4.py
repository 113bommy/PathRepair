n, m = map(int, input().split())

graph = [''] * n
for i in range(n):
    graph[i] = list(input())


def bfs(start):
    global graph

    layer, flag = {start}, False
    while layer:
        next_layer = set()
        for node in layer:
            i, j = node
            if j > 0 and graph[i][j - 1] == '.':
                graph[i][j - 1] = 'B' if flag else 'W'
                next_layer.add((i, j - 1))

            if j < m - 1 and graph[i][j + 1] == '.':
                graph[i][j + 1] = 'B' if flag else 'W'
                next_layer.add((i, j + 1))

            if i > 0 and graph[i - 1][j] == '.':
                graph[i - 1][j] = 'B' if flag else 'W'
                next_layer.add((i - 1, j))

            if i < n - 1 and graph[i + 1][j] == '.':
                graph[i + 1][j] = 'B' if flag else 'W'
                next_layer.add((i + 1, j))

        layer, flag = next_layer, not flag


for i in range(n):
    for j in range(m):
        if graph[i][j] == '.':
            graph[i][j] = 'B'
            bfs((i, j))

print('\n'.join(''.join(row) for row in graph))
