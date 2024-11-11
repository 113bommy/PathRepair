from collections import deque
from itertools import chain
H, W = map(int, input().split())
G = chain.from_iterable([[s == '#' for s in input()] for _ in range(H)])
dist = [0]*(H*W)
B = deque([i for i, g in enumerate(G) if g])
visited = set(B)
while B:
    vij = B.pop()
    for dij in (W, -W, 1, -1):
        nij = vij + dij
        if (dij == 1 and not nij % W) or (dij == -1 and not (nij+1) % W) or not (0 <= nij < H*W) or nij in visited:
            continue
        visited.add(nij)
        dist[nij] = 1 + dist[vij]
        B.appendleft(nij)
print(max(dist))
