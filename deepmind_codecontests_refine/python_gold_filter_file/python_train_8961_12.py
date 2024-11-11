n = int(input())
arr = list(map(int, input().split()))

graph = {i: set() for i in range(1, n+1)}
for i in range(n):
    graph[i+1] = graph[i+1].union(set([arr[i]]))

# print(graph)

ans = []
visited = set()
def dfs(graph, visited, node):
    if node not in visited:
        visited.add(node)
        for neighbors in graph[node]:
            # print(neighbors)
            dfs(graph, visited, neighbors)
    else:
        ans.append(node)
        return node


for i in range(n):
    visited.clear()
    dfs(graph, visited,i+1)
print(*ans)
