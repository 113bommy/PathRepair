from collections import deque
import sys
input = sys.stdin.readline

def bfs(graph, start):
    while graph != {}:
        start = min(graph.keys())
        queue = deque([])
        queue.append(start)
        pos = {}
        pos[start] = 0

        while queue:
            u = queue.popleft()
            for v,d in graph[u].items():
                if v not in pos:
                    pos[v] = pos[u] + d
                    if v in graph:
                        queue.append(v)
                elif pos[v] != pos[u] + d:
                    return False
            del graph[u]
            # print(queue)
        return True

n,m = map(int, input().split())

graph = {}
for i in range(m):
    l,r,d = map(int, input().split())
    if l not in graph:
        graph[l] = {}
    graph[l][r] = d
    if r not in graph:
        graph[r] = {}
    graph[r][l] = -d

if m == 0 or bfs(graph, min(graph.keys())):
    print('Yes')
else:
    print('No')
print(graph)