import collections

p = 10 ** 9 + 7
n, k = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(1, n):
    a, b, x = map(int, input().split())
    if (x == 0):
        graph[a].append(b)
        graph[b].append(a)

visited = [False] * (n + 1)
bad = 0
queue = collections.deque()

for i in range(1, n + 1):
    if not visited[i]:
        queue.append(i)
        visited[i] = True

        # calculate the size of the current connected component
        size_connected_component = 0
        while(queue):
            front = queue.pop()
            for adj_front in graph[front]:
                if not visited[adj_front]:
                    visited[adj_front] = True
                    queue.append(adj_front)
            size_connected_component += 1
        
        # calculate the number of bad sequence
        bad += pow(size_connected_component, k, p)

print((pow(n, k, p)- bad) % p)