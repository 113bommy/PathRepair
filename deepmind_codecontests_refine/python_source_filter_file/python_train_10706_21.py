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

from collections import deque

def bfs(graph: list, start: int):
    n = len(graph)
    dist = [-1]*n

    que = deque([(start, 0)])

    while que:
        cur_node, cur_dist = que.popleft()
        dist[cur_node] = cur_dist

        for nex in graph[cur_node]:
            if dist[nex] < 0:
                dist[nex] = cur_dist + 1
                que.append((nex, cur_dist+1))

    return dist

n = ni()

graph = [[] for _ in range(n)]
for _ in range(n-1):
    x, y = li_()
    graph[x].append(y)
    graph[y].append(x)

fenec = bfs(graph, 0)
snuke = bfs(graph, n-1)

fenec_saki = 0
for d1, d2 in zip(fenec, snuke):
    if d1 < d2:
        fenec_saki += 1
    elif d1 > d2:
        fenec_saki -= 1

if fenec_saki == 0:
    if n%2:
        print("Fennec")
    else:
        print("Snuke")

elif fenec_saki > 0:
    print("Fennec")

else:
    print("Snuke")
