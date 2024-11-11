import os
import sys

if os.getenv("LOCAL"):
    sys.stdin = open("_in.txt", "r")

sys.setrecursionlimit(10 ** 9)
INF = float("inf")
IINF = 10 ** 18
MOD = 10 ** 9 + 7


# MOD = 998244353


def argsort(li, key=None, reverse=False):
    return [i for _, i in sorted(
        [(a, i) for i, a in enumerate(li)], key=(lambda t: key(t[0])) if key else None, reverse=reverse
    )]


N, M = list(map(int, sys.stdin.buffer.readline().split()))
D = list(map(int, sys.stdin.buffer.readline().split()))
VU = [list(map(int, sys.stdin.buffer.readline().split())) for _ in range(M)]

graph = [[] for _ in range(N)]

for i, (v, u) in enumerate(VU):
    v -= 1
    u -= 1
    graph[v].append(u)
    graph[u].append(v)

edges = {}
colors = [None] * N
for v in argsort(D):
    d = D[v]
    if colors[v] is not None:
        continue
    for u in graph[v]:
        if colors[u] is not None:
            edges[v, u] = d
            colors[v] = not colors[u]
            break
        if D[u] == d:
            edges[v, u] = d
            colors[v] = True
            colors[u] = False
            break
    if colors[u] is None:
        print(-1)
        exit()
S = ''
for c in colors:
    S += 'B' if c else 'W'
ans = []
for v, u in VU:
    v -= 1
    u -= 1
    if (v, u) in edges:
        ans.append(edges[v, u])
    elif (u, v) in edges:
        ans.append(edges[u, v])
    else:
        ans.append(10 ** 9)

print(S)
print(*ans, sep='\n')
