n = int(input())
data = []
edge_list = []
graph = []
visited = []
for i in range(n):
    data.append([int(x) for x in input().split()])
    graph.append([])
    visited.append(0)
for i in range(n):
    for j in range(n):
        if i!=j and (data[i][0]==data[j][0] or data[i][1]==data[j][1]):
            graph[i].append(j)
queue = []

graph_count = 0
for i in range(n):
    if visited[i]==0:
        queue.append(i)
        while len(queue) > 0:
            poped = queue.pop(0)
            visited[poped]=1
            for neighbour in graph[i]:
                if visited[neighbour]==0 and neighbour not in queue:
                    queue.append(neighbour)
        graph_count += 1
print(graph_count-1)