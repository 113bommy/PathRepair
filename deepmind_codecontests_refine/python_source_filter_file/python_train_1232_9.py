import sys
sys.setrecursionlimit(20000)

N = int(input())

edges = {n: [] for n in range(N+1)}

for _ in range(N-1):
    a, b, c = map(int, input().split())

    edges[a].append((b, c))
    edges[b].append((a, c))

Q, K = map(int, input().split())
xy = []
for _ in range(Q):
    xy.append(tuple(map(int, input().split())))


d = [-1] * (N+1)
d[K] = 0


def dfs(n: int):
    for m, c in edges[n]:
        if d[m] == -1:
            d[m] = d[n] + c
            dfs(m)


dfs(K)

for x, y in xy:
    print(d[x] + d[y])