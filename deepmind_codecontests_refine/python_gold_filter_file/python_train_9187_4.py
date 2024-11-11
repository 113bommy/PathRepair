import sys
from collections import deque
input = sys.stdin.buffer.readline
print = sys.stdout.write

T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    e, inc = [[] for _ in range(n+1)], [0]*(n+1)
    edges = []
    for _ in range(m):
        a, b, c = map(int, input().split())
        edges.append((b, c))
        if a == 1:
            e[b].append(c)
            inc[c] += 1
    
    q = [u for u in range(1, n+1) if inc[u] == 0]
    tp = []
    while q:
        u = q.pop()
        tp.append(u)
        for v in e[u]:
            inc[v] -= 1
            if inc[v] == 0: q.append(v)
    if len(tp) < n: print("NO\n"); continue

    order = [0]*(n+1)
    for i, u in enumerate(tp): order[u] = i

    print("YES\n")
    for b, c in edges:
        if order[b] < order[c]: print("%d %d\n" % (b, c))
        else: print("%d %d\n" % (c, b))

