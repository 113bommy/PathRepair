import sys


def main():
    sys.setrecursionlimit(int(1e4))
    nvertices, nedges = map(int, input().split())
    Adj = [[] for i in range(nvertices)]
    Adjrev = [[] for i in range(nvertices)]
    for i in range(nedges):
        s, t = map(int, input().split())
        Adj[s].append(t)
        Adjrev[t].append(s)

    ordering = []
    visited = [False] * nvertices
    for u in range(nvertices):
        if not visited[u]:
            dfs1(u, Adj, visited, ordering)

    ordering.reverse()
    component_ids = [-1] * nvertices
    id = 0
    visited = [False] * nvertices
    for u in ordering:
        if visited[u]:
            continue
        dfs2(u, Adjrev, id, visited, component_ids)
        id += 1

    Q = int(input())
    for i in range(Q):
        s, t = map(int, input().split())
        if component_ids[s] == component_ids[t]:
            print(1)
        else:
            print(0)


def dfs1(u, Adj, visited, ordering):
    visited[u] = True
    for v in Adj[u]:
        if visited[v]:
            continue
        dfs1(v, Adj, visited, ordering)
    ordering.append(u)


def dfs2(u, Adj, id, visited, component_ids):
    visited[u] = True
    component_ids[u] = id
    for v in Adj[u]:
        if not visited[v]:
            dfs2(v, Adj, id, visited, component_ids)


main()