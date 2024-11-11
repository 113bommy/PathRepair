import sys
stdin = sys.stdin

sys.setrecursionlimit(10 ** 7)

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x) - 1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())



n, m = li()
edge = dict()
graph = [[] for _ in range(n)]
visited = [False]*n
par = [-1]*n
outs = [0]*n

for _ in range(m):
    a, b = li_()
    edge[(a, b)] = 0
    edge[(b, a)] = 0
    graph[a].append(b)
    graph[b].append(a)

def dfs(graph, visited, par, root, cur):

    for nex in graph[cur]:
        if visited[nex]:
            continue

        else:
            visited[nex] = True
            par[nex] = cur

            dfs(graph, visited, par, root, nex)

    if cur == root:
        return

    for neighbor in graph[cur]:
        if neighbor == par[cur]:
            continue

        if edge[(cur, neighbor)] != 0:
            continue

        edge[(cur, neighbor)] = 1
        edge[(neighbor, cur)] = -1

        outs[cur] += 1

    if outs[cur] % 2:
        edge[(cur, par[cur])] = 1
        edge[(par[cur], cur)] = -1
        outs[cur] += 1

    else:
        edge[(cur, par[cur])] = -1
        edge[(par[cur], cur)] = 1
        outs[par[cur]] += 1


if n % 2:
    print(-1)

else:
    visited[0] = True
    dfs(graph, visited, par, 0, 0)

    for (src, dst), val in edge.items():
        if val == 1:
            print(src+1, dst+1)