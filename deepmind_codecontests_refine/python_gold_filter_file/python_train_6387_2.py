def main():
    n, m = map(int, input().split())
    graph = Graph(n)
    for _ in range(m):
        v, w = map(int, input().split())
        graph.addEdge(v - 1, w - 1)

    marked = [False for _ in range(n)]
    toRemove = 0
    for i in range(n):
        if not marked[i]:
            count = dfs(graph, marked, i, -1, 0)
            if count is not None and count % 2 == 1:
                toRemove += 1

    if (n - toRemove) % 2 == 1:
        toRemove += 1

    print(toRemove)


class Graph:
    def __init__(self, vertices):
        self.adjList = [set() for _ in range(vertices)]

    def addEdge(self, v, w):
        self.adjList[w].add(v)
        self.adjList[v].add(w)

    def adjacentVertices(self, v):
        return self.adjList[v]


def dfs(graph, marked, vertex, parent, count):
    marked[vertex] = True
    count += 1
    for neighbour in graph.adjacentVertices(vertex):
        if neighbour == parent:
            continue
        elif marked[neighbour]:
            return count

        new_count = dfs(graph, marked, neighbour, vertex, count)
        if new_count is not None:
            return new_count

    return None


if __name__ == '__main__':
    main()
