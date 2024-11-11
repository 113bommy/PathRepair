import sys

sys.setrecursionlimit(10**5)
int1 = lambda x: int(x)-1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.buffer.readline())
def MI(): return map(int, sys.stdin.buffer.readline().split())
def MI1(): return map(int1, sys.stdin.buffer.readline().split())
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def BI(): return sys.stdin.buffer.readline().rstrip()
def SI(): return sys.stdin.buffer.readline().rstrip().decode()
inf = 10**16
md = 10**9+7
# md = 998244353

from collections import deque

for _ in range(II()):
    SI()
    n, m = MI()
    to = [[] for _ in range(n)]
    for _ in range(m):
        u, v = MI1()
        to[u].append(v)

    dd = [inf]*n
    dd[0] = 0
    q = deque()
    q.append((0, 0))
    while q:
        u, d = q.popleft()
        for v in to[u]:
            if dd[v] != inf: continue
            dd[v] = d+1
            q.append((v, d+1))

    ans = [inf]*n
    for u in range(n):
        if to[u]: ans[u] = min(dd[v] for v in to[u])
        ans[u] = min(ans[u], dd[u])

    topo = []
    fin = [False]*n
    def topo_sort(u):
        stack = [u]
        while stack:
            u = stack.pop()
            if fin[u]:
                topo.append(u)
            else:
                fin[u] = True
                stack.append(u)
                for v in to[u]:
                    if dd[v] <= dd[u]: continue
                    if fin[v]: continue
                    stack.append(v)

    for u in range(n):
        if fin[u]: continue
        topo_sort(u)

    for u in topo:
        for v in to[u]:
            if dd[v] <= dd[u]: continue
            ans[u] = min(ans[u], ans[v])

    print(*ans)
