H, W = map(int, input().split())
graph = []
for _ in range(H):
    graph.append(list(input()))

res = True

for i in range(1, W-1):
    for j in range(1, H-1):
        if graph[i][j] == '#' and graph[i + 1][j] == '.' and graph[i - 1][j] == '.' and graph[i][j + 1] == '.' and graph[i][j - 1] == '.':
            print('No')
            exit()
print('Yes')
