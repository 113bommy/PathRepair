from math import log2


L = int(input())
r = int(log2(L))
N = r + 1
edge = []
for i in range(r):
    edge.append((i + 1, i + 2, 2 ** i))
    edge.append((i + 1, i + 2, 0))
for t in range(N - 1, 0, -1):
    s = L - 2 ** (t - 1)
    if s >= 2 ** r:
        edge.append((t, N, s))
        L -= s

print(N, len(edge))
for e in edge:
    print(*e)
