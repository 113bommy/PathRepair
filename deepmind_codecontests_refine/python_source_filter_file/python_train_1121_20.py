import sys
input = sys.stdin.buffer.readline

from collections import deque

N, M = map(int, input().split())

X = [-10**9, 0, 10**9]
Y = [-10**9, 0, 10**9]

tate = []
yoko = []

for _ in range(N):
    a, b, c = map(int, input().split())
    X.append(a)
    X.append(b)
    Y.append(c)
    tate.append((a, b, c))

for _ in range(M):
    d, e, f = map(int, input().split())
    X.append(d)
    Y.append(e)
    Y.append(f)
    yoko.append((d, e, f))

X = sorted(set(X))
Y = sorted(set(Y))

Cx = {val: idx * 2 for idx, val in enumerate(X)}
Cy = {val: idx * 2 for idx, val in enumerate(Y)}

H = len(X) * 2 - 1
W = len(Y) * 2 - 1

G = [0] * (H * W)

for a, b, c in tate:
    j = Cy[c]
    for i in range(Cx[a], Cx[b] + 1):
        G[i * W + j] = -1

for d, e, f in yoko:
    i = Cx[d]
    for j in range(Cy[e], Cy[f] + 1):
        G[i * W + j] = -1

for i in range(1, H, 2):
    for j in range(1, W, 2):
        G[i * W + j] = (X[(i + 1) // 2] - X[(i - 1) // 2]) * (Y[(j + 1) // 2] - Y[(j - 1) // 2])

queue = [Cx[0] * W + Cy[0]]

visited = [0] * (H * W)
visited[Cx[0] * W + Cy[0]] = 1

res = 0

while queue:
    z = queue.pop()

    nz = z + W
    if G[nz] != -1 and not visited[nz]:
        nx = nz // W
        if nx == H - 1:
            print('INF')
            break
        visited[nz] = 1
        res += G[nz]
        queue.append(nz)

    nz = z - W
    if G[nz] != -1 and not visited[nz]:
        nx = nz // W
        if nx == 0:
            print('INF')
            break
        visited[nz] = 1
        res += G[nz]
        queue.append(nz)

    nz = z + 1
    if G[nz] != -1 and not visited[nz]:
        ny = nz % W
        if ny == W - 1:
            print('INF')
            break
        visited[nz] = 1
        res += G[nz]
        queue.append(nz)

    nz = z - 1
    if G[nz] != -1 and not visited[nz]:
        ny = nz % W
        if ny == 0:
            print('INF')
            break
        visited[nz] = 1
        res += G[nz]
        queue.append(nz)
else:
    print(res)